#!/bin/bash
# Compile the C code into object file as:
gcc -c  main.c 
# Compile the C++ code into object file as:
#g++ -c 
# Compile the Fortran  code into object file as:
gfortran -c random_vec.f90
# Link the object files with C as:
gcc -o out  main.o random_vec.o  -lgfortran
# run: out
./out
# clean:
# 	rm  -f *.o out
