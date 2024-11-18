#include <stdio.h>
#include <math.h>
#ifdef _OPENMP
#include <omp.h>
#endif

double f( double a )
{
    return (4.0 / (1.0 + a*a));
}

int main( int argc, char *argv[])
{
    int done = 0, n, i;
    double PI25DT = 3.141592653589793238462643;
    double pi, h, sum, x;
    double startwtime = 0.0, endwtime;
    
    n = 0;
    while (!done)
    {
            printf("Enter the number of intervals: (0 quits) \n");
            scanf("%d",&n);

            // The following statement is executed only if openmp is defined
            //startwtime = omp_get_wtime();
            

        if (n == 0)
            done = 1;
        else
        {
            h   = 1.0 / (double) n;
            sum = 0.0;
            // Insert parallel region, pay attention to  shared or private variables
            // and to the operations contained inside the the loop
            for (i = 1; i <= n; i++)
            {
                x = h * ((double)i - (double)0.5);
                sum += f(x);
            }
            pi = h * sum;
            
            printf("pi is approximately %.16f, Error is %.16f\n",
                       pi, fabs(pi - PI25DT));
            
            // The following statement is executed only if openmp is defined
           // endwtime = omp_get_wtime();
            

            printf("wall clock time = %f\n", endwtime-startwtime);
        }
    }

    return 0;
}


