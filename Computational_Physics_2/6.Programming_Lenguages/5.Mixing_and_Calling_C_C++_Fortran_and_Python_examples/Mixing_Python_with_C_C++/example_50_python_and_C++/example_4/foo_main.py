""" 
python install

The cppyy package provides fast, automatic, Python-C++ bindings, including run-time instantiation of C++ templates, cross-inheritance, callbacks, auto-casting, transparent use of smart pointers, etc., etc. Many C++ idioms are automatically recognized and "pythonized" (given a Python look-and-feel), allowing drop-in placement in Python idioms and integration with standard libraries such as NumPy and ctypes. Most importantly it makes it possible to write higher-level (with ownership, threading, and application-specific rules) Python modules on top of C++ in pure Python, without the need to learn an intermediate language or language extension.

Cppyy works by integrating the Clang/LLVM-based Cling C++ interpreter, providing interactive access to C/C++ from Python. It enables calling C++ from Python and calling Python from C++. Using precompiled modules, a class loader, and an everything-lazy implementation, cppyy is designed for automatic generation of Python bindings for large scale C++ programs. PyPy supports cppyy natively for high performance, as described in this PyHPC'16 paper.
python3 -m pip install cppyy

"""
import cppyy

cppyy.include("foo.h")
cppyy.load_library("foo")

from cppyy.gbl import Foo
f = Foo()
f.bar()


v = cppyy.gbl.std.vector[cppyy.gbl.Foo]()
v.push_back(f)
print(len(v))
print(v[0].bar())
