/*
https://nanxiao.me/en/clang-may-be-a-better-choice-than-gcc-in-developing-openmp-program/

clang++ -fopenmp parallel.cpp

*/

# cat parallel.cpp
#include <stdio.h>
#include <omp.h>

int main(void) {
    omp_set_num_threads(5);

    #pragma omp parallel for
    for (int i = 0; i < 5; i++) {

        #pragma omp taskloop
        for (int j = 0; j < 3; j++) {
            printf("%d\n", omp_get_thread_num());
        }

    }   
}
