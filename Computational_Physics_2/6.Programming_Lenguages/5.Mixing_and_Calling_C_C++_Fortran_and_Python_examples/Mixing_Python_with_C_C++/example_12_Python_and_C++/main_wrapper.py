"""
https://www.geeksforgeeks.org/how-to-call-c-c-from-python/
https://stackoverflow.com/questions/145270/calling-c-c-from-python
https://tech.blueyonder.com/python-calling-c++/
http://www.wgilpin.com/howto/howto_cython.html

g++ -c -fPIC geek.cpp -o geek.o
g++ -shared -Wl,-soname,libgeek.so -o libgeek.so geek.o

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

python3 main.py 


"""

## import the module
#from ctypes import cdll

## load the library
#lib = cdll.LoadLibrary('./libgeek.so')

## create a Geek class
#class Geek(object):

    ## constructor
    #def __init__(self):

        ## attribute
        #self.obj = lib.Geek_new()

    ## define method
    #def myFunction(self):
        #lib.Geek_myFunction(self.obj)

## create a Geek class object
#f = Geek()

## object method calling
#f.myFunction()


import ctypes
import sys
import pathlib  
        
# create a Geek class
class Geek(object):
    # constructor
    def __init__(self):
        # attribute
        self.obj = lib.Geek_new()
    # define method
    def myFunction(self):
        lib.Geek_myFunction(self.obj)

if __name__ == "__main__":
# find the shared library, the path depends on the platform and Python version    
    libname = pathlib.Path().absolute()
    print("libname: ", libname)

# 1. Load the shared library into c types.
    if sys.platform.startswith("win"):
        c_lib = ctypes.CDLL(libname / "cgeek.dll")
    else: # Linux
        c_lib = ctypes.CDLL(libname / "libgeek.so")
        
# create a Geek class object
    f = Geek()

# object method calling
    f.myFunction()        
