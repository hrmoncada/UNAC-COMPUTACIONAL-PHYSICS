#!/bin/bash
g++ -c -fPIC code.cpp -o code.so
g++ -shared -Wl,-soname,libcode.so -o libcode.so  code.so
