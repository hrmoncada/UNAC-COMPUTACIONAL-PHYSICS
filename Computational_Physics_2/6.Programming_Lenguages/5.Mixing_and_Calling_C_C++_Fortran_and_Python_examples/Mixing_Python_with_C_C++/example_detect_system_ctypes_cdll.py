'''
https://stackoverflow.com/questions/50168719/python-load-library-from-different-platform-windows-linux-or-os-x

ou can use the ctypes.cdll module to load the DLL/SO/DYLIB and the platform module to detect the system you are running on.


'''

import platform
from ctypes import *

# get the right filename
if platform.uname()[0] == "Windows":
    name = "win.dll"
elif platform.uname()[0] == "Linux":
    name = "linux.so"
else:
    name = "osx.dylib"
    
# load the library
lib = cdll.LoadLibrary(name)
