/***********************************************************************************
$ gcc -o out -fopenmp fibonacci.c 
$ ./out 40
Fibonacci number generator.
	Target number: 40
	Number of threads: 1
The 40th fibonacci number is: 102334155
Took 0.770840 seconds to compute.
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>

/***********************************************************************************/
double get_time() {
    struct timeval tp;
    struct timezone tzp;
    int i;

    i = gettimeofday(&tp,&tzp);
    return ( (double) tp.tv_sec + (double) tp.tv_usec * 1.e-6 );
}

/***********************************************************************************/
int fibonacci(const int n){
    if ( n < 2 ) return n;

    int x, y;

    x = fibonacci(n - 1);
    
    y = fibonacci(n - 2);

    return (x + y);
}

/***********************************************************************************/
int main(int argc, char **argv){
    if ( argc != 2 ){ // to ensuring that you will submit it right
       printf("ERROR: Invalid usage.\n");
       printf("Usage: ./fib.x N\n\tN: The Fibonacci number to compute.\n");
       return(1);
    }

    int fibN = atoi(argv[1]);
    int nthreads = 1;
    int output;

    printf("Fibonacci number generator.\n\tTarget number: %d\n\tNumber of threads: %d\n", fibN, nthreads);

    double start_time = get_time();
    output = fibonacci(fibN);
    double end_time = get_time();

    printf("The %dth fibonacci number is: %d\n", fibN, output);
    printf("Took %lf seconds to compute.\n", end_time - start_time);
}
