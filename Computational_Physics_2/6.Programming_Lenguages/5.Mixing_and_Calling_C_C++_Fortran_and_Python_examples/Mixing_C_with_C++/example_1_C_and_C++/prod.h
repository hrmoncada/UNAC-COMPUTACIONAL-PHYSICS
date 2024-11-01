
#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
  extern "C" {
#endif

   int prod_Int(int a, int b);
   float prod_Float(float a, float b);

#ifdef __cplusplus/* If this is a C++ compiler, end C linkage */
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
