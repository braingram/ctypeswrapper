#!/usr/bin/env python
"""
Take a namespace and dump it to a file
"""

import inspect
import StringIO

from . import parser
from . import structures


class Generator(object):
    def __init__(self, rep, library, output):
        self.rep = rep
        self.library = library
        self.output = output

    def line(self, s="", n=1):
        for _ in xrange(n):
            self.output.write(s + '\n')

    def header(self):
        self.line("#!/usr/bin/env python")
        self.line("import ctypes")
        self.line("import itertools")  # needed for arg_type_convert
        self.line(n=2)
        # define enum
        self.line(inspect.getsource(structures.Enum))
        self.line()
        # define function
        self.line(inspect.getsource(structures.arg_type_convert))
        self.line()
        self.line(inspect.getsource(structures.Function))

    def footer(self):
        pass

    def lib(self):
        self.line(
            "_lib = ctypes.cdll.LoadLibrary('{}')".format(self.library))
        self.line(n=2)

    def generate(self):
        self.header()
        self.lib()
        for (n, v) in self.rep:
            self.line(self.item(v, n))
        self.footer()

    def find_type_name(self, type_name):
        for n, d in self.rep:
            if getattr(d, '__name__', None) == type_name:
                return n

    def item(self, item, name=None, reference=False):
        # parse by module? might only be ctypes or ctypeswrapper
        if not hasattr(item, '__module__'):
            return "%s" % item
        if item.__module__ == 'ctypes':
            return self.ctypes_item(item, name, reference)
        else:
            return self.ctypeswrapper_item(item, name, reference)

    def ctypes_item(self, item, name=None, reference=False):
        if item.__name__ == 'LP_c_char':
            s = "ctypes.c_char_p"
        else:
            s = "ctypes.%s" % item.__name__
        if name is None:
            return s
        return "%s = %s" % (name, s)

    def ctypeswrapper_item(self, item, name=None, reference=False):
        tn = type(item).__name__
        if tn == 'PyCStructType':
            if reference:
                if name is not None:
                    raise Exception
                return self.find_type_name(item.__name__)
            return self.struct(item, name)
        elif tn == 'Enum':
            return self.enum(item, name)
        elif tn == 'Function':
            return self.function(item, name)
        elif tn == 'PyCPointerType':
            if reference:
                return "ctypes.POINTER(%s)" % \
                    self.find_type_name(item._type_.__name__)
            return self.pointer(item, name)
        elif tn == 'PyCArrayType':
            return self.array(item, name)
        else:
            raise Exception("Unknown type for %s, %s, %s" % (name, item, tn))

    def array(self, item, name=None):
        s = "ctypes.%s * %s" % (item._type_.__name__, item._length_)
        if name is None:
            return s
        return "%s = %s" % (name, item)

    def struct(self, item, name=None):
        if name is None:
            raise Exception("Invalid struct without name: %s" % item)
        r = "class %s(ctypes.Structure):\n" % name
        r += "    _fields_ = [\n"
        for fn, f in item._fields_:
            r += "        ('%s', %s),\n" % (fn, self.item(f, reference=True))
        r += "    ]\n\n"
        return r

    def enum(self, item, name=None):
        if name is None:
            raise Exception("Invalid enum without name: %s" % item)
        r = "%s = Enum('%s', [\n" % (name, name)
        for k in item:
            r += "    ('%s', %s),\n" % (k, item[k])
        r += "])\n\n"
        return r

    def function(self, item, name=None):
        if name is None:
            raise Exception("Invalid function without name: %s" % item)
        rt_string = self.item(item.restype, reference=True)
        r = "%s = Function(\n" % name
        r += "    '%s', %s,\n" % (name, rt_string)
        for (n, i) in item.args:
            r += "    ('%s', %s),\n" % (n, self.item(i, reference=True))
        r += ")\n"
        r += "%s.generate_spec(_lib)\n" % name
        return r
        # OLD
        arg_string = ', '.join([a for a, _ in item.args])
        # TODO return value
        # TODO set arg_types
        r = "def %s(%s):\n" % (name, arg_string)
        # convert arguments
        for (a, t) in item.args:
            vt = type(t).__name__
            if vt in ('PyCSimpleType', 'PyCStructType'):
                # by value
                r += "    %s = arg_type_convert(%s, %s, False)\n" % (
                    a, a, self.item(t, reference=True))
            elif vt == 'PyCPointerType':
                # by ref
                r += "    %s = arg_type_convert(%s, %s, True)\n" % (
                    a, a, self.item(t, reference=True))
            else:
                raise Exception("Unknown arg type {}".format(vt))
        # call function
        r += "    return lib.%s(%s)\n\n" % (name, arg_string)
        return r

    def pointer(self, item, name=None):
        # I think this is only pointers to functions at the moment
        if name is None:
            raise Exception("Pointer %s missing name" % item)
        if item._type_.__name__ == 'CFunctionType':
            f = item._func
            r = "%s = ctypes.CFUNCTYPE(\n" % name
            r += "    %s,\n" % self.item(f.restype, reference=True)
            for _, a in f.args:
                r += "    %s,\n" % self.item(a, reference=True)
            r += ")\n"
            return r
        else:
            raise Exception(
                "Invalid pointer %s type %s" % (name, item._type_.__name__))

    __call__ = generate


def dumps(rep, library):
    o = StringIO.StringIO()
    g = Generator(rep, library, o)
    g()
    g.output.seek(0)
    return g.output.read()


def dump(rep, library, f):
    g = Generator(rep, library, f)
    return g()


def generate(header_filename, output_filename, library_filename=None):
    rep = parser.parse_filename(
        header_filename, use_cpp=True, fake_stdlib=True)
    with open(output_filename, 'w') as f:
        dump(rep, library_filename, f)
