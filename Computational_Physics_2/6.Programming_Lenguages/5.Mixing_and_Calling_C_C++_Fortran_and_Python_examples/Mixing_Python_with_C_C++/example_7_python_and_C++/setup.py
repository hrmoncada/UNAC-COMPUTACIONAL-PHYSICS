'''
https://nesi.github.io/perf-training/python-scatter/ctypes
https://docs.python.org/3/distutils/setupscript.html
https://www.educative.io/answers/what-is-setuppy
https://docs.python.org/3/extending/building.html

The setup.py file is a Python file which indicates that the installation module/package is most likely packed and distributed using Distutils, the Python Module distribution standard. It specifies the contents of a module to Distutils so that it may execute the appropriate actions (such as locating dependencies) during the module’s first installation. The setup.py is a Python script typically included with Python-written libraries or apps. Its objective is to ensure that the program is installed correctly.

$ python3 setup.py build

'''
from setuptools import setup, Extension

## Compile *mysum.cpp* into a shared library 
#setup(
    ##...
    #ext_modules=[Extension('mysum', ['src/mysum.cpp'],),],
#)


module1 = Extension('mysum',
                    sources = ['src/mysum.cpp'])

setup (name = 'Mysum',
       version = '1.0',
       author = 'Henry R. Moncada',
       description = 'This is a demo package',
       long_description = '''This is really just a demo package.''',
       ext_modules = [module1])
