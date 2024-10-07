/* https://www.hackerearth.com/practice/notes/the-make-command-and-makefiles/
main.c 

$make -f Makefile_1

*/
#include <stdio.h>
#include <stdlib.h>

#include “a.h”

extern void function_two();
extern void function_three();

int main() {

    printf("run function_two\n");
    function_two();

    printf("run function_three\n");
    function_three();
    exit (EXIT_SUCCESS);
}