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

#ifdef __cplusplus
  extern "C" {
#endif

   int sumI(int a, int b);
   float sumF(float a, float b);

#ifdef __cplusplus
  } // end extern "C"
#endif
  
  /*
 Note: They are pre-compiler macros (preprocessor directives), and not Fortran statements.

#if defined(),   #ifdef,    #else,  and  endif 

They do the same as regular if statements, only at compile time and with a slightly different syntax.
Note that pre-processor directives are not part of any Fortran Standard, and that they are not supported by every compiler. 

Generally, they are identical to C pre-processor directives, but not always.
The difference between the two #if defined(), and  #ifdef, They are the same, except

ifdef can only use a single condition,  while 

#ifdef FOO

#if defined(NAME) can do compound conditionals.

#if defined(FOO)

to do several things at once, you can use \verb+#if defined(NAME)+, like

#if defined(FOO) || defined(BAR)

 */
