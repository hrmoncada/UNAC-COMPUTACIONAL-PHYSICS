
/*
https://www.appentra.com/parallel-computation-pi/
*/
#include <stdio.h>
#include <math.h>
#ifdef _OPENMP
#include <omp.h>
#endif

int main( int argc, char *argv[]) {



    x=0;
    sum = 0.0;
    step = 1.0/(double) num_steps;
#pragma omp parallel private(i,x) 
   {
#pragma omp for reduction(+:sum) schedule(static)
      for (i=0; i<num_steps; i=i+1){
         x=(i+0.5)*step;
         sum = sum + 4.0/(1.0+x*x);
      }
   }
   pi=step*sum;
   
      
       return 0;
}
