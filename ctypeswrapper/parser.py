#!/usr/bin/env python

import pycparser


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
    api['types'] = {}
    api['functions'] = {}
    api['structs'] = {}
    for _, child in ast.children():
        if isinstance(child, pycparser.c_ast.Typedef):
            # struct, typedef?
            if isinstance(child.type.type, pycparser.c_ast.Enum):
                api['types'][child.name] = parse_enum(child.type.type)
            elif isinstance(child.type.type, pycparser.c_ast.Struct):
                api['structs'][child.name] = parse_struct(child.type.type)
            elif isinstance(child.type.type, pycparser.c_ast.FuncDecl):
                print("Not yet supported, skipping")
                # TODO support this
                child.show()
            else:
                api['types'][child.name] = parse_decl(child.type)
            #elif isinstance(child.type.type, pycparser.c_ast.IdentifierType):
            #    # print("Typedef:{}:{}".format(
            #    #     child.name, child.type.type.names))
            #    api['types'][child.name] = child.type.type.names[0]
            #else:
            #    raise Exception("Unknown ast element: {}".format(child.show()))
        elif isinstance(child, pycparser.c_ast.Decl):
            api['functions'][child.name] = parse_function(child.type)
        else:
            raise Exception("Unknown ast element: {}".format(child.show()))
    return api


def parse_filename(fn, **kwargs):
    return parse_ast(pycparser.parse_file(fn, **kwargs))


def test():
    fn = '/usr/include/flycapture/C/FlyCapture2_C.h'
    kwargs = {
        'use_cpp': True,
        'cpp_args': ['-I/home/graham/Repositories/external/pycparser/utils/fake_libc_include'],
    }
    ast = pycparser.parse_file(fn, **kwargs)
    api = parse_filename(fn, **kwargs)
    return api, ast

if __name__ == '__main__':
    api, ast = test()
