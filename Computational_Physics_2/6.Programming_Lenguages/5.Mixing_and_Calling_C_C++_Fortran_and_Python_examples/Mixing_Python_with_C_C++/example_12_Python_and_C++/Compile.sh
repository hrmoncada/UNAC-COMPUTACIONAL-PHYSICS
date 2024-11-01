#!/bin/bash
g++ -c -fPIC geek.cpp -o geek.o
g++ -shared -Wl,-soname,libgeek.so -o libgeek.so geek.o
