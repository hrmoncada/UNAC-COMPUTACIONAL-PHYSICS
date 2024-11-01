/*https://www.toptal.com/c-plus-plus/c-plus-plus-understanding-compilation

$ gcc -c main.c 
$ nm main.o
                 U _GLOBAL_OFFSET_TABLE_
0000000000000000 T main
                 U printSumFloat
                 U printSumInt

 */
#include <stdio.h> 
#include "print_sum.hpp" // C++ header

int main(int argc, char* argv[]) {
    printf("Begin Program\n"); 
    
    printSumInt(1, 2);
    printSumFloat(1.5f, 2.5f);
    
    printf("End Program\n");
    return 0;
}
