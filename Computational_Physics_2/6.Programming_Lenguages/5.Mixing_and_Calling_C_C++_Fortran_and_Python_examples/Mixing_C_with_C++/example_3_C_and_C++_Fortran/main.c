/* https://www.cae.tntech.edu/help/programming/mixed_languages

Example 1: Main Program in C, with Subroutines in C, C++, and FORTRAN

@Compile the C++ code into object file as:
$ g++ -c cppfunction.C

@Compile the C code into object file as:
$ gcc -c main.c
$ gcc -c cfunction.c

@Compile the Fortran  code into object file as:
$ gfortran -c f90function.f90

@Link the object files:
$ gcc -o out  main.o f90function.o cppfunction.o cfunction.o

 */ 

#include <stdio.h>
#include "cppfunction.h"

int main(void) {
    float a=1.0, b=2.0;
    float x = 1.0, y = 2.0, z = 3.0;
    
    printf("Before running Fortran function:\n");
    printf("a = %f\n",a);
    printf("b = %f\n",b);
    
    ffunction_(&a, &b);

    avrage_(&x,&y,&z);
    
    printf("After running Fortran function:\n");
    printf("a = %f\n",a);
    printf("b = %f\n",b);

    printf("Before running C++ function:\n");
    printf("a = %f\n",a);
    printf("b = %f\n",b);
 
    cppfunction(&a, &b);
    
    printf("After running C++ function:\n");
    printf("a = %f\n",a);
    printf("b = %f\n",b);

    printf("Before running C function:\n");
    printf("a = %f\n",a);
    printf("b = %f\n",b);
    
    cfunction(&a, &b);
    
    printf("After running C function:\n");
    printf("a = %f\n",a);
    printf("b = %f\n",b);
    
    return 0;
}
