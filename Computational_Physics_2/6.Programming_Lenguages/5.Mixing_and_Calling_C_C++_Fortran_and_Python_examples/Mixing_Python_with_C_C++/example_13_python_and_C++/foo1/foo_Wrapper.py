'''
https://stackoverflow.com/questions/145270/calling-c-c-from-python
https://www.geeksforgeeks.org/how-to-call-c-c-from-python/
https://tech.blueyonder.com/python-calling-c++/
http://www.wgilpin.com/howto/howto_cython.html

g++ -c -fPIC foo.cpp -o foo.o
g++ -shared -Wl,-soname,libfoo.so -o libfoo.so foo.o

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

'''
#import the module
from ctypes import cdll

# load the library
lib = cdll.LoadLibrary('./libfoo.so')

# create a Geek class
class Foo(object):
	# constructor    
    def __init__(self):
        # attribute
        self.obj = lib.Foo_new()
    # define method
    def bar(self):
        lib.Foo_bar(self.obj)
        
if __name__ == "__main__":       
# create a Geek class object        
    f = Foo()

# object method calling
    f.bar() #and you will see "Hello" on the screen  
        
#import ctypes
#import sys
#import pathlib        

#if __name__ == "__main__":
    #libname = pathlib.Path().absolute()
    #print("libname: ", libname)

    ## Load the shared library into c types.
    #if sys.platform.startswith("win"):
        #c_lib = ctypes.CDLL(libname / "cmult.dll")
    #else:
        #c_lib = ctypes.CDLL(libname / "libfoo.so")

        
## create a Geek class object        
    #f = Foo()

## object method calling
    #f.bar() #and you will see "Hello" on the screen        
