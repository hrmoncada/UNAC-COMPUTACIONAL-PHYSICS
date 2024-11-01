'''
https://stackoverflow.com/questions/145270/calling-c-c-from-python
https://www.geeksforgeeks.org/how-to-call-c-c-from-python/
https://tech.blueyonder.com/python-calling-c++/
http://www.wgilpin.com/howto/howto_cython.html

1. 
g++ -c -fPIC mysum.cpp -o mysum.so
g++ -shared -Wl,-soname,libmysum.so -o libmysum.so  mysum.so

python3 main_2_wrapper.py 

or

bash 2.compile_and_run.sh


These are the eight best ways to check the installed version of the Python module ctypes:

Method 1: pip show ctypes
Method 2: pip list
Method 3: pip list | findstr ctypes
Method 4: library.__version__
Method 5: importlib.metadata.version
Method 6: conda list
Method 7: pip freeze
Method 8: pip freeze | grep ctypes

sudo apt-get install -y python-ctypes
'''
        
import ctypes
import sys
import pathlib       
import numpy

if __name__ == "__main__":
# find the shared library, the path depends on the platform and Python version    
    libname = pathlib.Path().absolute()
    print("libname: ", libname)

# 1. Load the shared library into c types.
    if sys.platform.startswith("win"):
        c_lib = ctypes.CDLL(libname / "build_2/cmysum.dll")
    else: # Linux
        c_lib = ctypes.CDLL(libname / "build_2/libmysum.so")
        
# 2. Tell Python the argument and result types of function mysum
    c_lib.mysum.restype = ctypes.c_longlong
    c_lib.mysum.argtypes = [ctypes.c_int, 
                        numpy.ctypeslib.ndpointer(dtype=numpy.int32)]        

    array = numpy.arange(0, 100000000, 1, numpy.int32)

# 3. call function mysum
    array_sum = c_lib.mysum(len(array), array)

    print('sum of array: {}'.format(array_sum))    
