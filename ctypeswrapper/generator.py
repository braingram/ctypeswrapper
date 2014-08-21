#!/usr/bin/env python
"""
Take a parsed representation (from parser.parse)
and generate ctypes bindings
"""

import ctypes


class NameSpace(object):
    def __init__(self, lib):
        # TODO what is the best way to handle this lib?
        self._lib = lib


def get_value_type(v):
    return type(v).__name__


def generate(representation, namespace):
    for (n, v) in representation:
        vt = get_value_type(v)
        # TODO this can probably be simplified
        if vt == 'PyCStructType':
            # struct
            setattr(namespace, n, v)
        elif vt == 'Function':
            # function
            # TODO generate calling spec
            v.generate_spec(namespace)
            setattr(namespace, n, v)
        elif vt == 'Enum':
            setattr(namespace, n, v)
        elif vt == 'PyCPointerType':
            # pointer to something?? TODO
            setattr(namespace, n, v)
        elif vt == 'PyCSimpleType':
            setattr(namespace, n, v)
        else:
            raise Exception(
                "Unknown representation value type {}".format(vt))
    return namespace
