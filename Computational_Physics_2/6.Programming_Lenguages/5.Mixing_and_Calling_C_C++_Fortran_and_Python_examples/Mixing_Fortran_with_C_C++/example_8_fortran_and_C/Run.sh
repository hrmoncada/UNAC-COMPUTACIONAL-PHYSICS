#!/bin/bash
# Compile the C code into object file as:
gcc -c init.c 
# Compile the C++ code into object file as:
#g++ -c 
# Compile the Fortran  code into object file as:
gfortran -c main.f90 init_mod.f90
# Link the object files with C as:
gcc -o out  main.o init_mod.o init.o -lgfortran
# run: out
./out
# clean:
# 	rm  -f *.o out
