/* Compiles the two .c files and names the executable out
 * The -I. is included so that gcc will look in the current directory (.) for the include file hello_make.h.

Compile:
$ gcc -o out hello_make.c hello_func.c -I.
 */

#include <hello_make.h>

int main() {
  // call a function in another file
  myPrintHelloMake();

  return(0);
}
