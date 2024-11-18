01 /*https://www.admin-magazine.com/HPC/Articles/Programming-with-OpenMP 
pi‑openmp.c (OpenMP version) 
$ gcc ‑Wall ‑fopenmp ‑o pi‑openmp pi‑openmp.c
$ export OMP_NUM_THREADS=1 ; time ./pi‑openmp
Pi = 3.141593
real    0m31.435s
user    0m31.430s
sys     0m0.004s
$ export OMP_NUM_THREADS=2 ; time ./pi‑openmp
Pi = 3.141593
real    0m15.792s
user    0m31.414s
sys     0m0.012s
*/
 
#include <stdio.h>
#define STEPCOUNTER 1000000000
int main(int argc, char *argv[]){
   long i;
   double pi = 0;
   #pragma omp parallel for reduction(+: pi)
   for (i = 0; i < STEPCOUNTER; i++) {
     /* pi/4 = 1/1 ‑ 1/3 + 1/5 ‑ 1/7 + ...
        To avoid the need to continually change
        the sign (s=1; in each step s=s*‑1),
        we add two elements at the same time. */
        pi += 1.0/(i*4.0 + 1.0);
        pi ‑= 1.0/(i*4.0 + 3.0);
   }
   pi = pi * 4.0;
  printf("Pi = %lf\n", pi);
  return 0;
}
