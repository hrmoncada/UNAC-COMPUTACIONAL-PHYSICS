#!/bin/bash
# Compile the C code into object file as:
gcc -c main.c prod.c swap.c initialize_array.c
# Compile the C++ code into object file as:
g++ -c print_prod.cpp pass_by_ref.cpp array_product.cpp
# Compile the Fortran  code into object file as:
gfortran -c farray_product.f90
# Link the object files with C as:
g++ -o out main.o print_prod.o prod.o pass_by_ref.o  swap.o array_product.o initialize_array.o  farray_product.o -lgfortran
# run: out
./out
# clean:
# 	rm  -f *.o out
