#!/bin/bash
# Compile the C code into object file as:
gcc -c  Cfunction.c	 
# Compile the C++ code into object file as:
#g++ -c cppfunction.cpp		
# Compile the Fortran  code into object file as:
gfortran -c main.f90	
# Link the object files with C as:
gfortran -o out  main.o Cfunction.o  
# run: out
./out
# clean:
# 	rm  -f *.o out
