#!/bin/bash
# Compile the C code into object file as:
# gcc -c cfunction.c	
# Compile the C++ code into object file as:
g++ -c main.cpp #cppfunction.cpp
# Compile the Fortran  code into object file as:
gfortran -c f90function.f90	
# Link the object files with C++ as:
g++ -o out  main.o f90function.o -lgfortran #cfunction.o  cppfunction.o 
# run: out
./out
# clean:
# 	rm  -f *.o out
