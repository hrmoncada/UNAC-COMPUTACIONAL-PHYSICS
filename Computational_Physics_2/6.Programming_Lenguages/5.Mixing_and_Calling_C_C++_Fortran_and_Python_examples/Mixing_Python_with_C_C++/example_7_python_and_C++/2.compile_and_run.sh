#!/bin/bash
mkdir build_2
g++ -c -fPIC src/mysum.cpp -o build_2/mysum.so
g++ -shared -Wl,-soname,libmysum.so -o build_2/libmysum.so  build_2/mysum.so
python3 main_1_wrapper.py
