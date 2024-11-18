// https://docs-dev.nersc.gov/cgpu/examples/
// compiled with the GCC Fortran compiler gfortran from the gcc/8.1.1-openacc-gcc-8-branch-20190215 module:
// $ clang -fopenmp -fopenmp-targets=nvptx64-nvidia-cuda -o main.ex main.c
// $ srun -n 1 nvprof ./main.ex

#include <stdio.h>

#define MAX 32768

int main()
{
  int x[MAX], i;
  for (i = 0; i < MAX; ++i) {
    x[i] = 42;
  }

  #pragma omp target teams distribute parallel for simd map(tofrom: x[0:MAX])
  for (i = 0; i < MAX; ++i) {
    x[i] = x[i] + 1;
  }
  printf("After the target region is executed, x[0] = %d\n", x[0]);
  return 0;
}
