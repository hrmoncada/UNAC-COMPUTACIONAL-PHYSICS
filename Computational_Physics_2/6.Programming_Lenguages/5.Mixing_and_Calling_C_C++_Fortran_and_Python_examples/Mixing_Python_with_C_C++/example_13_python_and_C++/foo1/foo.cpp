/*
https://stackoverflow.com/questions/145270/calling-c-c-from-python

g++ -c -fPIC foo.cpp -o foo.so
g++ -shared -Wl,-soname,libfoo.so -o libfoo.so  foo.so

*/
#include <iostream>

using namespace std;

class Foo{
    public:
        void bar(){
           cout << "Hello World" << endl;
        }
};
