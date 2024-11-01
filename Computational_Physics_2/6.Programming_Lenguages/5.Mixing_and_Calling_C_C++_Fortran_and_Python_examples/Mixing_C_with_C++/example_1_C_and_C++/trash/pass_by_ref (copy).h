/*
If I include this header from a C source file, 

   voif foo()

If I include them from a C++ source file, 

extern "C" {

 voif foo()
   
} // end extern "C"
 */

void extern array_product_f90_(double *a, double *b, double  *c, int n, double *productC);
#ifndef _PASS_BY_REF_H_
#define _PASS_BY_REF_H_

#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
  extern "C" {
#endif
// C++
  double array_product_cpp(double *a, double *b, double *c, int n);
  void pass_int_by_ref(int *a); 
// C  
  void swap(int *x, int *y);
  double initialize_array(double *a, double *b, int n);
// Fortran
  
#ifdef __cplusplus /* If this is a C++ compiler, end C linkage */
  } // end extern "C"
#endif
  
#endif /* _PASS_BY_REF_H_ */
  
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
