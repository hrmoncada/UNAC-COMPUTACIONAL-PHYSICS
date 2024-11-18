/* https://www.stolaf.edu/people/rab/os/pub0/modules/Pi_Integration_SharedMemory/OpenMP/OpenMP.html 
 Estimate pi as twice the area under a semicircle
 Command-line arguments (optional, default values below).
  1. first command line arg is integer number of rectangles to use
  2. if two command-line args, second arg is number of OpenMP threads
 WARNING:  minimal error checking is performed on these command-line args 
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* parameters that may be overridden on the command-line */
long n_rect = 10485760;         /* default number of rectangles */
int threadct = 8;               /* default number of OpenMP threads to use */

int main(int argc, char** argv) {
double a = -1.0, b = 1.0;  /* lower and upper interval endpoints */
double h;               /* width of a rectangle subinterval */
double f(double x);     /* declare function that defines curve */
double sum;             /* accumulates areas all rectangles so far */
long i;  /* loop control */
 /* parse command-line arguments, if any */
if (argc > 1)
n_rect = strtol(argv[1], NULL, 10);
if (argc > 2)
    threadct = strtol(argv[2], NULL, 10);
if (n_rect <= 0 || threadct <= 0) {
    printf("Error in command-line argument(s)\n");
        return 1;  /* indicates error exit */
}

h = (b - a)/n_rect;

/* compute the estimate */
 sum = 0;
#pragma omp parallel for num_threads(threadct) \
shared (a, n_rect, h) private(i) reduction(+: sum)
for (i = 0; i < n_rect; i++) {
     sum += f(a + (i+0.5)*h) * h;
}
printf("With n = %d rectangles and %d threads, ", n_rect, threadct);
printf("the estimate of pi is %.20g\n", sum);
return 0;
}

double f(double x) {
return 2*sqrt(1-x*x);
}
