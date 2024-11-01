/* https://www.cae.tntech.edu/help/programming/mixed_languages
 * http://www.yolinux.com/TUTORIALS/LinuxTutorialMixingFortranAndC.html
https://stackoverflow.com/questions/28943465/mixing-code-in-c-c-and-fortran

Example 2: Main Program in C++, with Subroutines in C, C++, and FORTRAN

@Compile the C code into object file as:
$ gcc -c cfunction.c

@Compile the C++ code into object file as:
$ g++ -c main.cpp
$ g++ -c cppfunction.cpp

@Compile the Fortran  code into object file as:
$ gfortran -c f90function.f90

@Link the object files:
$ g++ -o out  main.o f90function.o cppfunction.o cfunction.o
 */ 


#include <iostream>  

using namespace std;

// extern "C" {
//   void f90function_(float *a, float *b);
// }
// 
// extern "C" {
//   void cfunction(float *a, float *b);
// }
// 
// void cppfunction(float *a, float *b);



// extern "C" {
// // C and Fortran90 subrotines    
//   void f90function_(float *a, float *b);
//   void cfunction(float *a, float *b);
// 
// } // end extern "C"
// 
// // C++ subrotines
// void cppfunction(float *a, float *b);
//    

#include "pass_by_ref.hpp"

int main() {
      float a = 1.0, b = 2.0;

      cout << "Before running Fortran function:" << endl;
      cout << "a=" << a << endl;
      cout << "b=" << b << endl;
//Fortra90
      f90function_(&a, &b);

      cout << "After running Fortran function:" << endl;
      cout << "a=" << a << endl;
      cout << "b=" << b << endl;

      cout << "Before running C function:" << endl;
      cout << "a=" << a << endl;
      cout << "b=" << b << endl;
// C
      cfunction(&a, &b);

      cout << "After running C function:" << endl;
      cout << "a=" << a << endl;
      cout << "b=" << b << endl;

      cout << "Before running C++ function:" << endl;
      cout << "a=" << a << endl;
      cout << "b=" << b << endl;
// CPP
      cppfunction(&a, &b);

      cout << "After running C++ function:" << endl;
      cout << "a=" << a << endl;
      cout << "b=" << b << endl;

      return 0;
}
