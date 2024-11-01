#!/bin/bash
# Compile the C code into object file as:
gcc -c  cfunction.c	 main.c
# Compile the C++ code into object file as:
g++ -c cppfunction.cpp		
# Compile the Fortran  code into object file as:
gfortran -c f90function.f90	f90subroutine.f90	
# Link the object files with C as:
gcc -o out  main.o f90subroutine.o f90function.o cppfunction.o cfunction.o 
# run: out
./out
# clean:
# 	rm  -f *.o out
