#!/usr/bin/env python
"""
Take a namespace and dump it to a file
"""


def dumps(namespace, gen=False, line_separator='\n'):
    if not gen:
        return line_separator.join(list(dumps.gen(namespace, gen=True)))
    yield "import ctypes"
    yield ""
    yield ""
    yield "ctypes.cdll.LoadLibrary({})".format(namespace._lib._name)
    yield ""
    for n, v in namespace._rep:
        vt = type(v).__name__
        if vt == 'PyCSimpleType':
            yield "{} = ctypes.{}".format(n, v.__name__)
        elif vt == 'PyCPointerType':
            # TODO not sure what to do here
            raise Exception
        elif vt == 'Function':
            # TODO
            raise Exception
        elif vt == 'Enum':
            # TODO
            raise Exception


def dump(namespace, file):
    pass
