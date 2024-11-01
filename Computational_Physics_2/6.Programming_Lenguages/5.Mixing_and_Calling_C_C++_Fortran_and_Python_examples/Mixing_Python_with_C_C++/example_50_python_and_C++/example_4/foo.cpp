/* https://stackoverflow.com/questions/145270/calling-c-c-from-python
 * cat foo.cpp
Compile it:

$ g++ -c -fPIC foo.cpp -o foo.o
$ g++ -shared -Wl,-soname,libfoo.so -o libfoo.so  foo.o
 */
#include "foo.h"
#include <iostream>

using namespace std;

void Foo::bar() { 
    cout << "Hello World" << endl;    
}
