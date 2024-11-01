'''
https://stackoverflow.com/questions/145270/calling-c-c-from-python
https://cppyy.readthedocs.io/en/latest/

cppyy is an automatic, run-time, Python-C++ bindings generator, for calling C++ from Python and Python from C++. 

python3 main_wrapper.py 

'''
import cppyy

cppyy.include("foo.h")
cppyy.load_library("foo")

from cppyy.gbl import Foo

f = Foo()
f.bar()
