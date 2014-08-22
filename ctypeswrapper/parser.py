#!/usr/bin/env python

import copy
import ctypes
import itertools

import pycparser

# rather than monkey-patch ctypes, include other common types here
base_types = {
    'uchar': ctypes.c_ubyte,
    'void': None,
}

unary_ops = {
    '-': lambda v: -v,
    '+': lambda v: +v,
}


def ctype_from_names(names, other_types=None):
    """Given ast.names lookup a matching ctype"""
    t = None
    signed = True
    length = None
    for n in names:
        if n == 'unsigned':
            signed = False
        elif n == 'signed':
            signed = True
        elif (n == 'long') and (length is None):
            length = 'long'
        elif n == 'short':
            length = 'short'
        else:
            t = n
    if length == 'short':
        t = 'short'
    elif length == 'long':
        if t in (None, 'int'):
            t = 'long'
        elif t == 'long':
            t = 'longlong'
        else:
            t = 'longdouble'
    if not signed:
        t = 'u{}'.format(t)
    else:
        t = '{}'.format(t)
    if other_types is not None and t in other_types:
        return other_types[t]
    if t in base_types:
        return base_types[t]
    return getattr(ctypes, 'c_{}'.format(t))


class Enum(dict):
    def __init__(self, name, *args, **kwargs):
        dict.__init__(self, *args, **kwargs)
        self.reverse = dict([(self[n], n) for n in self])
        self.name = name

    def name_to_value(self, name):
        return dict.__getitem__(self, name)

    def value_to_name(self, value):
        return self.reverse[value]

    def __getitem__(self, k):
        if isinstance(k, (str, unicode)):
            return self.name_to_value(k)
        elif isinstance(k, int):
            return self.value_to_name(k)
        else:
            raise ValueError(
                "Invalid enum key {}, must be str, unicode or int: {}".format(
                    k, type(k)))


def arg_type_convert(v, atype=None, ptype=None, byref=None):
    """
    This needs to know the un-pointered type when arg by value
    """
    if byref:
        if type(v) == atype:
            return v
        # this should be a simple ctype that will be pointed to
        if type(v).__module__ == 'ctypes':  # this is a valid ctypes object
            return ctypes.byref(v)
        if type(type(v)).__module__ == '_ctypes':  # defined struct, etc
            return ctypes.byref(v)
        # this is a non-ctypes object, so making it into a ctypes object
        # would 'shadow' the arg, causing any change to the generated
        # ctype object to be lost. so throw an exception
        raise Exception(
            "Arguments passed by reference must "
            "be ctypes object: {}, {}".format(v, type(v)))
    if type(v) != atype:
        return atype(v)
    return v


class Function(object):
    def __init__(self, name, restype, *args):
        self.name = name
        self.restype = restype
        self.args = args
        self.func = None
        self.lib = None
        self.converter = None

    def as_ctype(self):
        return ctypes.CFUNCTYPE(self.restype, *[a[1] for a in self.args])

    def generate_spec(self, namespace):
        # TODO do I need the namespace here... probably for typedefs
        self.converter = []
        # TODO generate converter for __call__, maybe even a *gasp* doc string
        for n, vt in self.args:
            argtype = type(vt).__name__  # this is a type of a type
            if argtype == 'PyCSimpleType':  # pass by value
                self.converter.append(
                    lambda v, a=vt, b=False:
                    arg_type_convert(v, a, b)
                    )
            elif argtype == 'PyCPointerType':  # pass by ref
                self.converter.append(
                    lambda v, a=vt, b=True:
                    arg_type_convert(v, a, b)
                    )
            elif argtype == 'PyCStructType':
                self.converter.append(
                    lambda v, a=vt, b=False:
                    arg_type_convert(v, a, b)
                    )
            else:
                raise Exception(
                    "Unknown arg type {} for {} {}".format(argtype, n, vt))
        self.assign_lib(namespace._lib)
        self.__doc__ = 'args: {}'.format(self.args)

    def assign_lib(self, lib):
        self.lib = lib
        self.func = getattr(self.lib, self.name)
        self.func.restype = self.restype
        self.func.argtypes = [v for _, v in self.args]

    def __call__(self, *args):
        if self.func is None:
            raise Exception(
                "Function has not been bound to a library: see assign_lib")
        if self.converter is None:
            raise Exception(
                "Function spec has not been generated: see generate_spec")
        if len(self.converter) != len(args):
            raise Exception(
                "Invalid number of args {} != {}".format(
                    len(args), len(self.converter)))
        return self.func(*[
            c(a) for (c, a) in itertools.izip(self.converter, args)])


class ASTParser(object):
    def __init__(self, types=None):
        if types is not None:
            self.types = copy.deepcopy(types)
        else:
            self.types = {}

    def parse(self, ast, *args, **kwargs):
        t = type(ast).__name__
        if not hasattr(self, t):
            print("Unknown ast type: {}".format(t))
            ast.show()
            raise Exception("Unknown ast type: {}".format(t))
        else:
            return getattr(self, type(ast).__name__)(ast, *args, **kwargs)

    def Enum(self, ast, name=None):
        name = ast.name
        objects = []
        for e in ast.values.enumerators:
            n, v = self.parse(e, objects=objects)
            objects.append((n, v))
        e = Enum(name, objects)
        return e

    def Enumerator(self, ast, objects=None):
        if hasattr(ast, 'value') and ast.value is not None:
            if isinstance(ast.value, pycparser.c_ast.ID):
                # TODO handle this better
                for (n, v) in objects:
                    if n == ast.value.name:
                        return (ast.name, v)
                ast.value.show()
                raise Exception("Failed to parse: {}".format(ast.value))
            else:
                return (ast.name, self.parse(ast.value))
        else:
            if len(objects):
                return (ast.name, objects[-1][1] + 1)
            else:
                return (ast.name, 0)

    def Struct(self, ast, name=None):
        if ast.name is not None:
            name = ast.name
        return type(name, (ctypes.Structure, ), {
            '_fields_': [self.parse(d) for d in ast.decls]})

    def Typedef(self, ast):
        t = self.parse(ast.type, name=ast.name)
        if isinstance(t, Enum):
            self.types[ast.name] = ctypes.c_int
        elif isinstance(t, Function):
            return t.as_ctype()
        else:
            self.types[ast.name] = t
        return ast.name, t

    def TypeDecl(self, ast, *args, **kwargs):
        return self.parse(ast.type, *args, **kwargs)

    def Decl(self, ast):
        return ast.name, self.parse(ast.type, name=ast.name)

    def ArrayDecl(self, ast, *args, **kwargs):
        return self.parse(ast.type) * self.parse(ast.dim)

    def IdentifierType(self, ast, *args, **kwargs):
        return ctype_from_names(ast.names, self.types)

    def PtrDecl(self, ast, *args, **kwargs):
        v = self.parse(ast.type, *args, **kwargs)
        if isinstance(v, Function):
            return ctypes.POINTER(v.as_ctype())
        else:
            return ctypes.POINTER(v)

    def Constant(self, ast):
        return eval(ast.value)  # TODO make this less dangerous

    def BinaryOp(self, ast):
        return eval(
            str(self.parse(ast.left)) + ast.op + str(self.parse(ast.right)))

    def UnaryOp(self, ast):
        if ast.op in unary_ops:
            op = unary_ops[ast.op]
        else:
            op = getattr(ctypes, ast.op)
        return op(self.parse(ast.expr))

    def Typename(self, ast):
        return self.parse(ast.type)

    def FileAST(self, ast):
        r = []
        for _, c in ast.children():
            r.append(self.parse(c))
        return r

    def Cast(self, ast):
        return self.parse(ast.to_type)(self.parse(ast.expr)).value

    def FuncDecl(self, ast, name=None):
        ret = self.parse(ast.type)
        args = []
        if ast.args is not None:
            for p in ast.args.params:
                # pointer?
                arg = self.parse(p)
                args.append(arg)
        return Function(name, ret, *args)


def parse_filename(fn, **kwargs):
    ast = pycparser.parse_file(fn, **kwargs)
    parser = ASTParser()
    r = parser.parse(ast)
    return r


def test():
    #fn = '/usr/include/flycapture/C/FlyCapture2_C.h'
    fn = 'foo.h'
    kwargs = {
        'use_cpp': True,
        'cpp_args': ['-nostdinc', '-P'],
    }
    ast = pycparser.parse_file(fn, **kwargs)
    return None, ast
    api = parse_filename(fn, **kwargs)
    return api, ast

if __name__ == '__main__':
    api, ast = test()
    p = ASTParser()
