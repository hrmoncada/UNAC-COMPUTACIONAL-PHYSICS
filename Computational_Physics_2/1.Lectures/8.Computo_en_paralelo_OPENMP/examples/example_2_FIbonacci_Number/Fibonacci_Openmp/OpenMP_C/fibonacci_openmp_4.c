/* https://books.google.com/books?id=qIERUAp-vVAC&pg=PA132&lpg=PA132&dq=fortran+90+,+f,+openmp,+fibonaccionacci&source=bl&ots=W3YSdzXAWA&sig=ACfU3U1fZFYeXO7XyocBcHRlIf51rrsT5A&hl=en&sa=X&ved=2ahUKEwiZq_jS1bTrAhUQXc
page 132

$ gcc -fopenmp -o out fibonacci_openmp_4.c 
$ ./out 40
Fibonacci number generator.
	Target number: 40
	Number of threads: 8
fibonacci(40) = 102334155

*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#pragma css task input(a) output(out)
int fibonacci(int a, int *out) {
  int tmp1, tmp2;
  
  if (a <= 1)
    *out=1;
  else {
    fibonacci(a-1, &tmp1);
    
    fibonacci(a-2, &tmp2);
    *out =  tmp1 + tmp2;
   }
}

int main(int argc, char **argv){
   //int var = 50;
   int result ;
    if ( argc != 2 ){ // to ensuring that you will submit it right
        printf("ERROR: Invalid usage.\n");
        printf("Usage: ./fib.x N\n\tN: The Fibonacci number to compute.\n");
        return(1);
    }

    int var = atoi(argv[1]);  
    int nthreads = 1;
    #pragma omp parallel
    {
       #pragma omp master
        nthreads = omp_get_num_threads();
    }

    printf("Fibonacci number generator.\n\tTarget number: %d\n\tNumber of threads: %d\n", var, nthreads);
    
   #pragma css start
   fibonacci(var-1, &result);
   
   #pragma css finish
   printf ("fibonacci(%d) = %d\n", var, result);
   
   return 0;
}
