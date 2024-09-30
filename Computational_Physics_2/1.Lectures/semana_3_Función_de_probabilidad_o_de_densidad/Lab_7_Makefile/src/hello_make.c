/* Compiles the two .c files and names the executable out
 * The -I. is included so that gcc will look in the current directory (.) for the include file hello_make.h.
 * 
 *Compile:
 * 
 * gcc -o out src/hello_make.c lib/hello_func.c -I.
 * 
 * 
 */

//#include <hello_make.h>
#include <stdio.h>
#include "../include/hello_make.h"

int main() {
  // call a function in another file
  int p = 6; 
  myPrintHelloMake(&p);
  printf("p = %d\n", p);
  return 0;
}
