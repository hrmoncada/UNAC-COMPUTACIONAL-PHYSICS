#!/usr/bin/env python
'''
https://stackoverflow.com/questions/145270/calling-c-c-from-python

Using SWIG, we generate a C++ interface source code from the SWIG interface definition file..

swig -c++ -python code.i

We finally compile the generated C++ interface source file and link everything together to generate a shared library that is directly importable by Python (the "_" matters):

g++ -c -fPIC code_wrap.cxx  -I/usr/include/python2.7 -I/usr/lib/python2.7
g++ -shared -Wl,-soname,_code.so -o _code.so code.o code_wrap.o

'''
import code
a= [[3,5,7],[8,10,12]]
print a
b = code.average(a)
print "Assignment done"
print a
print b
