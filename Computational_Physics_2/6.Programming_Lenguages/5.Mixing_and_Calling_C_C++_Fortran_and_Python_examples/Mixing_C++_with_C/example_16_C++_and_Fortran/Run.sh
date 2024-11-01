#!/bin/bash
# Compile the C++ code into object file as:
 g++ -c main.cpp	
# Compile the C code into object file as:
# gcc -c cfunction.c		
# Compile the Fortran  code into object file as:
gfortran -c matrix_multi.f90	
# Link the object files with Fortran90 as:
g++ -o out  main.o  matrix_multi.o -lgfortran
# run: out
./out
# clean:
# 	rm  -f *.o out
