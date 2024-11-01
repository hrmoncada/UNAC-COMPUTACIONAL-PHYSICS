#!/usr/bin/env python
'''
We first compile the C++ code to create an object file:
g++ -c -fPIC code.cpp

Using SWIG, we generate a C++ interface source code from the SWIG interface definition file..

swig -c++ -python code.i

'''
import code
a = [[3,5,7],[8,10,12]]
print (a)
b = code.average(a)
print ("Assignment done"0
print (a)
print (b)
