/* C example: PI
https://www.mcs.anl.gov/research/projects/mpi/tutorial/mpiexmpl/src/pi/C/main.html
http://hamilton.nuigalway.ie/teaching/AOS/NINE/MPI.htm 
This exercise presents a simple program to determine the value of pi. The algorithm suggested here is chosen for its simplicity. 
The method evaluates the integral of 4/(1+x*x) between 0 and 1. The method is simple: the integral is approximated by a sum of n intervals;
the approximation to the integral in each interval is (1/n)*4/(1+x*x). The master process (rank 0) asks the user for the number of intervals;
the master should then broadcast this number to all of the other processes. Each process then adds up every n'th interval (x = rank/n, rank/n+size/n,...). 
Finally, the sums computed by each process are added together using a reduction.
*/

#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"                /* Include MPI header file that contains the library’s API */
#include <math.h> 

int main (int argc, char* argv[]) {
 int done = 0, n, myid, numprocs, i, rc; 
 double PI25DT = 3.141592653589793238462643; double mypi, pi, h, sum, x, a;
 
 MPI_Init(&argc,&argv); 
 MPI_Comm_size(MPI_COMM_WORLD,&numprocs); 
 MPI_Comm_rank(MPI_COMM_WORLD,&myid);

 while (!done){ 
    if (myid == 0) { 
        printf("Enter the number of intervals: (0 quits) "); 
        scanf("%d",&n); 
    }
 
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD); 

    if (n == 0) break; 

    h = 1.0 / (double) n; 
    sum = 0.0; 
    for (i = myid + 1; i <= n; i += numprocs) { 
        x = h * ((double)i - 0.5); 
        sum += 4.0 / (1.0 + x*x); 
    } 
    mypi = h * sum;

    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (myid == 0) 
        printf("pi is approximately %.16f, Error is %.16f\n", pi, fabs(pi - PI25DT)); 
 } 

  MPI_Finalize(); 
    
  return 0;
}
