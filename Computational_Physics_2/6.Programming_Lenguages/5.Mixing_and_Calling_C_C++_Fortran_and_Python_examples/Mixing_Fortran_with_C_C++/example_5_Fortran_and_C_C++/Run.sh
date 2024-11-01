#!/bin/bash
# Compile the C++ code into object file as:
g++ -c  cppfunction.cpp	
# Compile the C code into object file as:
gcc -c cfunction.c		
# Compile the Fortran  code into object file as:
gfortran -c main.f90 f90function.f90	
# Link the object files with g++ as:
gfortran -o out  main.o f90function.o cppfunction.o cfunction.o
# run: out
./out
# clean:
# 	rm  -f *.o out
