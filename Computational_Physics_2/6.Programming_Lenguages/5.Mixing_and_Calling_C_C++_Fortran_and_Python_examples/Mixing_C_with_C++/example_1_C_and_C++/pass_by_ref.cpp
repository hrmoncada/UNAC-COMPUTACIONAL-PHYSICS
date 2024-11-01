#include <iostream> // std::cout, std::endl
#include <string>

#include "pass_by_ref.h" // C header

using namespace std;

void cpp_pass_int_by_ref(int *alpha){
   string str = "   Pass value by reference in C++"; 
   cout << str << endl;
   *alpha  = *alpha  + 100;
   cout << "   alpha  + 100 = " << *alpha  << endl;
}

// void foo(float a){
//    string str = "FOO foo f00n"; 
//    cout << str << endl;
//    a = a + 100;
// }
