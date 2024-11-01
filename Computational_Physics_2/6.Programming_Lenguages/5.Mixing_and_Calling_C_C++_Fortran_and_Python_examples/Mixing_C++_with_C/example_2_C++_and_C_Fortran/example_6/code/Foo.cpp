#include "Foo.hpp"
#include <iostream>
using namespace std;


Foo::Foo(int _a, int _b): a(_a), b(_b){
    cout << "C++ side, constructor" << endl;
}

Foo::~Foo(){
    cout << "C++ side, destructor" << endl;
}

int Foo::bar(int c) const{
    return a + c;
}

double Foo::baz(double d) const{
    return d + b;
}

void foo_speaker(string s){
    Foo f(4, 2);
    cout << s << " Foo(4, 2).bar(3) is: " <<  f.bar(3) << endl;
}
