#!/bin/bash
# Compile the C code into object file as:
gcc -c main.c sum.c
# Compile the C++ code into object file as:
g++ -c print_sum.cpp 
# Link the object files with C++ as:
g++ -o out sum.o print_sum.o main.o
# run: out
./out
# clean:
# 	rm  -f *.o out
