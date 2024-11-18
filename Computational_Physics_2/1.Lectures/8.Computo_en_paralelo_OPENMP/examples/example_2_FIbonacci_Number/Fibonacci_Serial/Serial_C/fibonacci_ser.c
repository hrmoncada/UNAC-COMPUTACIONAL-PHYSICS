#include <stdio.h>

int fib(int n)
{
  int i, j;
  if (n<2)
    return n;
  else
    {
       
       i=fib(n-1);

       
       j=fib(n-2);

       
       return i+j;
    }
}

int main()
{
  int n = 10;

//  omp_set_dynamic(0);
//  omp_set_num_threads(4);
  
    printf ("fib(%d) = %d\n", n, fib(n));
  
}
