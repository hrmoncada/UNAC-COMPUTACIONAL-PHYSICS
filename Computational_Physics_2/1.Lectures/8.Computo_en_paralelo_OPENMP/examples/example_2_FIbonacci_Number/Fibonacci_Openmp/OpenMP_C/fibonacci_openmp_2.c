/*https://docs.oracle.com/cd/E19205-01/820-7883/girtd/index.html

(base) Fiona:C$ gcc -fopenmp -o out fibonacci_openmp_2.c 
(base) Fiona:C$ ./out 40
Fibonacci number generator.
	Target number: 40
	Number of threads: 8
fibonacci(40) = 102334155

*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int fibonacci(int n) {
  int i, j;
  if (n < 2)
    return n;
  else {
       #pragma omp task shared(i) firstprivate(n)
       i=fibonacci(n-1);

       #pragma omp task shared(j) firstprivate(n)
       j=fibonacci(n-2);

       #pragma omp taskwait
       return i+j;
    }
}

int main(int argc, char **argv){
   if ( argc != 2 ){ // to ensuring that you will submit it right
        printf("ERROR: Invalid usage.\n");
        printf("Usage: ./fib.x N\n\tN: The Fibonacci number to compute.\n");
        return(1);
    }

    int n = atoi(argv[1]);
    int nthreads = 1;
     #pragma omp parallel
    {
       #pragma omp master
         nthreads = omp_get_num_threads();
    }

    printf("Fibonacci number generator.\n\tTarget number: %d\n\tNumber of threads: %d\n", n, nthreads);
  
    omp_set_dynamic(0);
    omp_set_num_threads(4);

    #pragma omp parallel shared(n)
    {
      #pragma omp single
      printf ("fibonacci(%d) = %d\n", n, fibonacci(n));
    }
    return 0;
}

