/*
 * https://stackoverflow.com/questions/145270/calling-c-c-from-python
 * */
#include <iostream>
#include "foo.h"

using namespace std;

void Foo::bar() { 
    cout << "Hello World" << endl;
}
