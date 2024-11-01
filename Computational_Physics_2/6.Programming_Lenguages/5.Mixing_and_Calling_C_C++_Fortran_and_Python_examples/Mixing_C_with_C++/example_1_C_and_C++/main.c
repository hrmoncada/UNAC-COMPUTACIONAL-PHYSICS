/* https://binarypirates.wordpress.com/2010/08/29/mixing-c-cpp-code/
 *https://www.geeksforgeeks.org/extern-c-in-c/
 * 
COMPILING THE OBJECT FILES

@Compile the C++ code into object file as:

g++ -c  print_prod.cpp  pass_by_ref.cpp

@Compile the C code into object file as:

gcc -c  main.c prod.c swap.c

@Link both the object files:

gcc -o out  main.o print_prod.o prod.o pass_by_ref.o  swap.o

Note that we cannot use gcc compiler because it won’t be able to link to C++ libraries.
We should link with g++ compiler.

@Execute the program we get the desired output:

$ ./main

FOO foo f00

*/
#include <stdio.h> 
#include "pass_by_ref.h" // C header
#include "print_prod.hpp" // C++ header

int main(int argc, char *argv[]){
/* local variable definition */
  int a = 100;
  int b = 200;
  int alpha = 20;
      
  printf("Begin Program\n"); 
  
// C++ subroutine
  printf("before alpha  = %d\n", alpha ); 
  cpp_pass_int_by_ref(&alpha); 
  printf("After alpha  = %d\n", alpha );
  
// C++ subroutine
  print_prod_Int(1, 2);       
  print_prod_Float(1.5f, 2.5f);
  
// C subroutine  
  int n = 5;
  double aa[n], bb[n], cc[n];// = {}; // empty array created error "stack smashing detected"  

  c_initialize_array(aa, bb, n);
  
// C++ subroutine  
  double result = cpp_array_product(aa, bb, cc, n); 
  
  for(int i = 0; i < n ; i++){
      printf("%3.1f * %3.1f = %3.1f\n", aa[i], bb[i], cc[i]); 
  }
  
  printf("2^n =  a[]*b[] = %3.2f\n",result);
  
// C subroutine  
  printf("Before swap, value of (a : b) = (%d, %d)\n", a, b );
  c_swap(&a, &b); 
  printf("After swap, value of (a : b) = (%d, %d)\n", a, b);
  
// // Fortran subroutine   
  float fa[n], fb[n], fc[n];
  float productC = 1.0;
  for(int i = 0; i < n; i++){
      fa[i] = 1.0;
      fb[i] = 2.0;
      fc[i] = 0.0;
    } 
    
    for(int i = 0; i < n ; i++){
      printf("%3.1f * %3.1f =  %3.1f\n", fa[i], fb[i], fc[i]); 
    } 
  
  f90_array_product_(fa, fb, fc, n, &productC);   
//   
//   for(int i = 0; i < n ; i++){
//       printf("%3.1f * %3.1f =  %3.1f\n", aa[i], bb[i], cc[i]); 
//   }
//   
//   printf("\n 2^n =  a[]*b[] = %3.2f\n",productC);
//   
//   printf("End Program\n");
  
 
  
  return 0;
}
