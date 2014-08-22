an(other) automatic ctypes wrapper generator.

Motivation
------
I wanted something that worked like ctypesgen but also:

- handled enums (often used for error codes, etc.)
- handled function arg by reference conversion
- could generate wrappers on-the-fly

Example
------

```python
import ctypeswrapper

foo = ctypeswrapper.wrap('foo.h', 'foo.so')
```

Dependencies
------
pycparser
gcc

Installation
------
soon...
