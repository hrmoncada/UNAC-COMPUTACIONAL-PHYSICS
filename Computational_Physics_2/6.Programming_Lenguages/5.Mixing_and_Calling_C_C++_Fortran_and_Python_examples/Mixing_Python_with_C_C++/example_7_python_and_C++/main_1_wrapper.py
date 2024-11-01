'''
https://nesi.github.io/perf-training/python-scatter/ctypes

1. The fact that mysum.cpp has the .cpp extension indicates that the source file is written in C++. Compile the code with the command.

$ python3 setup.py build
running build
running build_ext
building 'mysum' extension
x86_64-linux-gnu-gcc -pthread -Wno-unused-result -Wsign-compare -DNDEBUG -g -fwrapv -O2 -Wall -g -fstack-protector-strong -Wformat -Werror=format-security -g -fwrapv -O2 -g -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2 -fPIC -I/usr/include/python3.8 -c mysum.cpp -o build/temp.linux-x86_64-3.8/mysum.o
creating build/lib.linux-x86_64-3.8
x86_64-linux-gnu-g++ -pthread -shared -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-Bsymbolic-functions -Wl,-z,relro -g -fwrapv -O2 -Wl,-Bsymbolic-functions -Wl,-z,relro -g -fwrapv -O2 -g -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2 build/temp.linux-x86_64-3.8/mysum.o -o build/lib.linux-x86_64-3.8/mysum.cpython-38-x86_64-linux-gnu.so

This will compile the code and produce a shared library under  "build/lib.linux-x86_64-3.8"

2. Calling mysum from Python
$ python3 main_1_wrapper.py
 
sum of array: 4999999950000000

or

bash 1.compile_and_run.sh

'''
import ctypes
import numpy
import glob

# find the shared library, the path depends on the platform and Python version
libfile = glob.glob('build/*/mysum*.so')[0]

# 1. open the shared library
mylib = ctypes.CDLL(libfile)

# 2. tell Python the argument and result types of function mysum
# long long                   <=   ctypes.c_longlong
#           mysum(            
#                 int n,      <=   ctypes.c_int
#                 int* array  <=   numpy.ctypeslib.ndpointer(dtype=numpy.int32)
#           )
mylib.mysum.restype = ctypes.c_longlong
mylib.mysum.argtypes = [ctypes.c_int, 
                        numpy.ctypeslib.ndpointer(dtype=numpy.int32)]

size = 100000000

array = numpy.arange(0, size , 1, numpy.int32)
print(array)

print(len(array))

# 3. call function mysum
array_sum = mylib.mysum(len(array), array)

print('sum of array: {}'.format(array_sum))
