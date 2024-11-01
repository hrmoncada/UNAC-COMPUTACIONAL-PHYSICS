#!/bin/bash
# Compile the C code into object file as:
gcc -c main.c
# Compile the C++ code into object file as:
#g++ -c
# Compile the Fortran  code into object file as:
gfortran -c kronrod.f90
# Link the object files with C as:
gcc -o out main.o kronrod.o -lgfortran -lm
# run: out
./out
# clean:
# 	rm  -f *.o out
