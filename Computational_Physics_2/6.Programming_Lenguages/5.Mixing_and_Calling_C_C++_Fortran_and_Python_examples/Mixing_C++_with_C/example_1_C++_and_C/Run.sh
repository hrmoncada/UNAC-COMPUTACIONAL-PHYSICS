#!/bin/bash
# Compile the C code into object file as:
gcc -c  cfunction.c	
# Compile the C++ code into object file as:
g++ -c  main.cpp Fredd.cpp		
# Link the object files with C as:
g++ -o out  main.o Fredd.o cfunction.o 
# run: out
./out
# clean:
# 	rm  -f *.o out
