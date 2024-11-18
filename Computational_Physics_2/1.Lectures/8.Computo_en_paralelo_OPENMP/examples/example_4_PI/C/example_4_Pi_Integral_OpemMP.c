/*
https://stackoverflow.com/questions/40171162/openmp-paralellize-pi-program
*/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

long num_steps = 100000;
double step    = 1.0/100000.0;

int main() {
int i;
double x, pi, sum = 0.0;

#pragma omp parallel private(x) 
{
    #pragma omp for reduction(+:sum)
    for(i = 0; i < num_steps; ++i) {
     x = (i-0.5)*step;
     sum += 4.0/(1.0+x*x);
    }

}


pi = step*sum;
printf("PI value = %f\n", pi);

       return 0;
}
