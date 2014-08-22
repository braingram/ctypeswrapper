#!/usr/bin/env python


def wrap(header_filename, library_filename):
    lib = ctypes.cdll.LoadLibrary(library_filename)
    rep = parser.parse_filename(header_filename)
