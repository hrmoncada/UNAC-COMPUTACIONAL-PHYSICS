#!/usr/bin/env python
""" Simple examples of calling C functions through ctypes module.

Diana:c$ invoke build-cmult
==================================================
= Building C Library 
* Complete

Diana:c$ invoke test-ctypes
==================================================
= Testing ctypes Module for C 
libname:  /home/hrmoncada/Desktop/TOOls/GNU_GCC_C_C++_C#/Examples/Mixing_and_Calling_C_C++_Fortran_and_Python_examples/Mixing_with_Python/example_1_python_materials-python-bindings/c
    In cmult : int 6 float 2.3 returning  13.8
    In Python: int: 6 float 2.3 return val 47.0

    In cmult : int 6 float 2.3 returning  13.8
    In Python: int: 6 float 2.3 return val 13.8
Diana:c$ 
 """
import ctypes
import sys
import pathlib

if __name__ == "__main__":
    libname = pathlib.Path().absolute()
    print("libname: ", libname)

    # Load the shared library into c types.
    if sys.platform.startswith("win"):
        c_lib = ctypes.CDLL(libname / "cmult.dll")
    else:
        c_lib = ctypes.CDLL(libname / "libcmult.so")

    # Sample data for our call:
    x, y = 6, 2.3

    # This will not work:
    # answer = c_lib.cmult(x, y)

    # This produces a bad answer:
    answer = c_lib.cmult(x, ctypes.c_float(y))
    print(f"    In Python: int: {x} float {y:.1f} return val {answer:.1f}")
    print()

    # You need tell ctypes that the function returns a float
    c_lib.cmult.restype = ctypes.c_float
    answer = c_lib.cmult(x, ctypes.c_float(y))
    print(f"    In Python: int: {x} float {y:.1f} return val {answer:.1f}")
