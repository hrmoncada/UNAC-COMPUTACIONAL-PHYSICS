#include <iostream>
using namespace std;

// extern "C" {
//   void cppfunction(float *a, float *b);
// }

void cppfunction(float *a, float *b) {
    *a = 5.0;
    *b = 6.0;
     cout << "C++function (a, b) = " << "("<< *a <<", " << *b << ")" << endl;
}
