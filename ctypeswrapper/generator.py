#!/usr/bin/env python

import ctypes


type_lookup = {
    'int': ctypes.c_int,
    'unsigned int': ctypes.c_uint,
    'float': ctypes.c_float,
}


def generate(ast):
    pass
