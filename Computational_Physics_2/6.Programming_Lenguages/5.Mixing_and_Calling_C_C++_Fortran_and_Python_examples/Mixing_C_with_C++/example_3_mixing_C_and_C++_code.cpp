/*
http://www-igm.univ-mlv.fr/~dr/CPP/c++-faq/mixing-c-and-cpp.html
*/

#include <iostream>  

using namespace std;

/* If you have an individual C function that you want to call, and for some reason you don't have or don't want to #include a C header file in which that function is declared, you can declare the individual C function in your C code using the extern C syntax. Naturally you need to use the full function prototype: */

extern "C" void f(int i, char c, float x);

// A block of several C functions can be grouped via braces:

extern "C" {
      void   f(int i, char c, float x);
//       int    g(char* s, const char* s2);
//       double sqrtOfSumOfSquares(double a, double b);
}

// After this you simply call the function just as if it was a C++ function:

int main() {
    
   f(7, 'x', 3.14);   // Note: nothing unusual in the call
   return 0;
}

