/*
Note also that since print.cpp is a C++ source file, compiled with a C++ compiler (g++), all the code in it is compiled as C++ code. 

Functions with C linkage like printSumInt and printSumFloat are also C++ functions that can use C++ features. Only the names of the symbols are compatible with C, but the code is C++, which can be seen by the fact that both functions are calling an overloaded function (printSum), which couldn’t happen if printSumInt or printSumFloat were compiled in C.

Let’s see now print.hpp, a header file that can be included both from C or C++ source files, which will allow printSumInt and printSumFloat to be called both from C and from C++, and printSum to be called from C++

If we include print.hpp from a C source file, we just want to see:

   void foo_Int(int a);


If we include print.hpp from a C++ source file, the __cplusplus preprocessor macro will be defined and the file will be seen as:

  void foo_Int(int a);
  
  extern "C" {


  } // end extern "C"

 */

#ifdef __cplusplus
 // void foo_Int(int a);  // C

  extern "C" {
#endif

   void foo_Int(int *a);  // C++

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
