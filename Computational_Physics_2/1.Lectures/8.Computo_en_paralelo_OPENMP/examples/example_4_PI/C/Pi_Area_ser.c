#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _OPENMP
#include <omp.h>
#endif

int main( int argc, char *argv[])
{
    int done = 0, n, i;
    double PI25DT = 3.141592653589793238462643;
    double pi, h;
    double x, y, x1, x2, y1, y2;
    int SqPoints, CiPoints;
    double startwtime = 0.0, endwtime;
    
    n = 0;
    while (!done)
    {
        
            printf("Enter the number of points: (0 quits) \n");
            scanf("%d",&n);
            
            // The following statement is executed only if openmp is defined
            //startwtime = omp_get_wtime();
            

            
        if (n <= 0)
            done = 1;
        else
        {
            x1 = -1.0;
            x2 = 1.0;
            y1 = -1.0;
            y2 = 1.0;
            SqPoints  = 0;
            CiPoints  = 0;

            // Insert parallel region, pay attention to  shared or private variables
            // and to the operations contained inside the the loop
            for (i = 1; i <= n; i++)
            {
                x = rand(); 
                x = x / RAND_MAX; 
                x = x1 + x * (x2 - x1);
                y = rand(); 
                y = y / RAND_MAX; 
                y = y1 + y * (y2 - y1);
                SqPoints++;
                if ( sqrt( x*x + y*y ) <= 1.0 ) CiPoints++;
            }

            pi = 4.0 * (double)CiPoints / (double)SqPoints;
            printf("pi is approximately %.16f, Error is %.16f\n",
                       pi, fabs(pi - PI25DT));
              
            // The following statement is executed only if openmp is defined
            //endwtime = omp_get_wtime();
            

             printf("wall clock time = %f\n",
                       endwtime-startwtime);
        }
    }

    return 0;
}


