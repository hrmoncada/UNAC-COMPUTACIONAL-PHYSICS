#!/bin/bash
# Compile the C code into object file as:
gcc -c  cfunction.c		
# Compile the Fortran  code into object file as:
gfortran -c main.f90	
# Link the object files with Fortran90 as:
gfortran -o out  main.o cfunction.o
# run: out
./out
# clean:
# 	rm  -f *.o out
