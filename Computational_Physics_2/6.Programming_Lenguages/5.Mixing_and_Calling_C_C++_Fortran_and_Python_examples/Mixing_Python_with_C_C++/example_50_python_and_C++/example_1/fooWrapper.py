"""
https://stackoverflow.com/questions/145270/calling-c-c-from-python
"""
from ctypes import cdll
lib = cdll.LoadLibrary('./libfoo.so')

class Foo(object):
    def __init__(self):
        self.obj = lib.Foo_new()

    def bar(self):
        lib.Foo_bar(self.obj)

if __name__ == '__main__':    
  f = Foo()
  f.bar() #and you will see "Hello" on the screen        
