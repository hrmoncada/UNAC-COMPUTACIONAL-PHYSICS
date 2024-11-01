#!/bin/bash
# Compile the C++ code into object file as:
g++ -c main.cpp cppfunction.cpp
# Compile the C code into object file as:
gcc -c cfunction.c	
# Link the object files with C++ as:
g++ -o out  main.o cfunction.o cppfunction.o
# run: out
./out
# clean:
# 	rm  -f *.o out
