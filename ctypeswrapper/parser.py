#!/usr/bin/env python

import copy
import ctypes

import pycparser

# rather than monkey-patch ctypes, include other common types here
base_types = {
    'uchar': ctypes.c_ubyte,
    'void': None,
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
            return None
        else:
            return getattr(self, type(ast).__name__)(ast, *args, **kwargs)

    def Enum(self, ast, name=None):
        raise Exception
        pass

    def Struct(self, ast, name=None):
        if ast.name is not None:
            name = ast.name
        return type(name, (ctypes.Structure, ), {
            '_fields_': [self.parse(d) for d in ast.decls]})

    def Typedef(self, ast):
        t = self.parse(ast.type, name=ast.name)
        self.types[ast.name] = t
        return ast.name, t

    def TypeDecl(self, ast, *args, **kwargs):
        return self.parse(ast.type, *args, **kwargs)

    def Decl(self, ast):
        return ast.name, self.parse(ast.type)

    def ArrayDecl(self, ast, *args, **kwargs):
        return self.parse(ast.type) * self.parse(ast.dim)

    def IdentifierType(self, ast, *args, **kwargs):
        return ctype_from_names(ast.names, self.types)

    def PtrDecl(self, ast, *args, **kwargs):
        return ctypes.POINTER(self.parse(ast.type, *args, **kwargs))

    def Constant(self, ast):
        return eval(ast.value)  # TODO make this less dangerous

    def BinaryOp(self, ast):
        return eval(
            str(self.parse(ast.left)) + ast.op + str(self.parse(ast.right)))

    def UnaryOp(self, ast):
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


def parse_enum(ast):
    enum = {}
    v = 0
    for _, e in ast.values.children():
        if e.value is None:
            enum[e.name] = v
        elif isinstance(e.value, pycparser.c_ast.ID):
            enum[e.name] = enum[e.value.name]
        elif isinstance(e.value, pycparser.c_ast.Constant):
            enum[e.name] = eval(e.value.value)
        elif isinstance(e.value, pycparser.c_ast.UnaryOp):
            enum[e.name] = eval(e.value.expr.value)
        v = enum[e.name] + 1
    return enum


def parse_struct(ast):
    struct = {}
    for d in ast.decls:
        struct[d.name] = parse_decl(d.type)
    ast.show()
    print(struct)
    return struct


def parse_decl(ast):
    if isinstance(ast, pycparser.c_ast.TypeDecl):
        return parse_decl(ast.type)
    elif isinstance(ast, pycparser.c_ast.PtrDecl):
        decl = parse_decl(ast.type.type)
        decl['access'] += '*'
        return decl
    elif isinstance(ast, pycparser.c_ast.ArrayDecl):
        decl = parse_decl(ast.type.type)
        decl['dim'] = ast.dim.value
        return decl
    else:
        if not isinstance(ast, pycparser.c_ast.IdentifierType):
            raise Exception("Expected IdentifierType: {}".format(ast))
        return {
            'type': ' '.join(ast.names),
            'access': '',
        }


def parse_function(ast):
    ret = parse_decl(ast.type)
    args = []
    if ast.args is not None:
        for p in ast.args.params:
            # pointer?
            arg = parse_decl(p.type)
            arg['name'] = p.name
            args.append(arg)
    return {'return': ret, 'args': args}


def parse_ast(ast):
    api = {}
    api['typedefs'] = {}
    api['declarations'] = {}
    for _, child in ast.children():
        if isinstance(child, pycparser.c_ast.Typedef):
            api['typedefs'][child.name] = parse_typedef(child.type)
        elif isinstance(child, pycparser.c_ast.Decl):
            api['declarations'][child.name] = parse_decl(child.type)
        else:
            raise Exception("Unknown ast element: {}".format(child.show()))
    # old
    #        # struct, typedef?
    #        if isinstance(child.type.type, pycparser.c_ast.Enum):
    #            api['types'][child.name] = parse_enum(child.type.type)
    #        elif isinstance(child.type.type, pycparser.c_ast.Struct):
    #            api['structs'][child.name] = parse_struct(child.type.type)
    #        elif isinstance(child.type.type, pycparser.c_ast.FuncDecl):
    #            print("Not yet supported, skipping")
    #            # TODO support this
    #            child.show()
    #        else:
    #            api['types'][child.name] = parse_decl(child.type)
    #    elif isinstance(child, pycparser.c_ast.Decl):
    #        api['functions'][child.name] = parse_function(child.type)
    #    else:
    return api


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
