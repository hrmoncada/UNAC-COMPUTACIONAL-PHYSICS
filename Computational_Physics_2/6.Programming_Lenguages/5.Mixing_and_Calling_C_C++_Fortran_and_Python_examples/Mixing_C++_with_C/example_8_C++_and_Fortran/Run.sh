#!/bin/bash
# Compile the C++ code into object file as:
g++ -c main.cpp
# Compile the Fortran  code into object file as:
gfortran -c f90function.f90 square.f90
# Link the object files with C++ as:
g++ -o out  main.o f90function.o  square.o -lgfortran
#-lg2c
# run: out
./out
# clean:
# 	rm  -f *.o out
