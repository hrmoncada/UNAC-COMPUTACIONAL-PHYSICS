#include "foo.h"
#include "Foo.hpp"

#include <iostream>
using namespace std;

FOO* create_foo(int a, int b){
    cout << "C API, create_foo" << endl;
    return new Foo(a, b);
}

void delete_foo(FOO* foo){
    cout << "C API, delete_foo" << endl;
    delete foo;
}

int foo_bar(const FOO* foo, int c){
    return foo->bar(c);
}

double foo_baz(const FOO* foo, double d){
    return foo->baz(d);
}

void foo_speaker(const char* s) {
    foo_speaker(string(s));
}
