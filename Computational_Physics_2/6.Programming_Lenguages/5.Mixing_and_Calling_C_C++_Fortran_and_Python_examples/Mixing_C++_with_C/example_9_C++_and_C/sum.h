/*
If I include this header from a C source file, 

   int sumI(int a, int b);
   float sumF(float a, float b);

If I include them from a C++ source file, 

extern "C" {

   int sumI(int a, int b);
   float sumF(float a, float b);
   
} // end extern "C"

C language doesn’t know anything about the extern "C" directive, 
but C++ does, and it needs this directive applied to C function declarations.
This is because C++ mangles function (and method) names because
it supports function/method overloading, while C doesn’t.
*/

#ifdef __cplusplus/* If this is a C++ compiler, use C linkage */
  extern "C" {
#endif
// C subrotines, these functions get C linkage 
   int sumI(int a, int b);
   float sumF(float a, float b);

#ifdef __cplusplus/* If this is a C++ compiler, close off the extern declaration. */
  } // end extern "C"
#endif
