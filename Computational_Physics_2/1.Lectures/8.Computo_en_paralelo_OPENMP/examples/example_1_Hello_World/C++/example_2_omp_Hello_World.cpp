/* https://askubuntu.com/questions/900702/how-to-compiler-openmp-program-using-clang
test.c
clang test.c -fopenmp
./a.out
thread 0
thread 5
thread 2
thread 1
thread 7
thread 3
thread 4
thread 6
*/
#include "omp.h"
#include <stdio.h>

int main(void) {
  #pragma omp parallel
  printf("thread %d\n", omp_get_thread_num());
}
