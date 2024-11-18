/*****************************************************************************
                    C-DAC Tech Workshop : hyPACK-2013 
                         October 15-18, 2013 

 Example 2.1           : omp-pi-calculation.c

 Objective             : Write an OpenMP program to compute the value of pi
                 	 function by numerical integration of a function
                 	 f(x) = 4/(1+x*x ) between the limits 0 and 1
                 	 This example demonstrates the use of PARALLEL FOR
                 	 DIRECTIVE with usage of Private clause and
                 	 Critical Section

 Input                :  Number of threads
                	  Number of intervals

 Output               : Each thread calculates the partial sum and then the master
                 	 thread prints the final PI value and time taken for 
                 	 computation.
	                                            
 Created              : August-2013

 E-mail               : hpcfte@cdac.in     

************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>
#include<omp.h>

#define PI 3.1415926538837211

/* Main Program */
main(int argc,char **argv)
{
	int             Noofintervals, i,Noofthreads,threadid;
	double           x, totalsum, h;
	struct timeval  TimeValue_Start;
        struct timezone TimeZone_Start;

        struct timeval  TimeValue_Final;
        struct timezone TimeZone_Final;
        long            time_start, time_end;
        double          time_overhead;


	printf("\n\t\t---------------------------------------------------------------------------");
        printf("\n\t\t Centre for Development of Advanced Computing (C-DAC)");
        printf("\n\t\t Email : hpcfte@cdac.in");
        printf("\n\t\t---------------------------------------------------------------------------");
        printf("\n\t\t Objective : OpenMP Numerical Computation - PI Computation  ");
        printf("\n\t\t Computation of PI using Numerical Integration method .");
        printf("\n\t\t OpenMP Parallel for directive,Private Clause and Critical Section  ");
        printf("\n\t\t..........................................................................\n");

         /* Checking for command line arguments */
        if( argc != 3 ){

           printf("\t\t Very Few Arguments\n ");
           printf("\t\t Syntax : exec <Threads> <no. of interval>\n");
           exit(-1);
        }

        Noofthreads=atoi(argv[1]);
        if ((Noofthreads!=1) && (Noofthreads!=2) && (Noofthreads!=4) && (Noofthreads!=8) && (Noofthreads!= 16) ) {
               printf("\n Number of threads should be 1,2,4,8 or 16 for the execution of program. \n\n");
               exit(-1);
         }

        Noofintervals=atoi(argv[2]);

        printf("\n\t\t Threads : %d ",Noofthreads);

      /*	printf("\n\t\t Enter number of intervals\n");
	scanf("%d", &Noofintervals);
*/

	/* No. of intervals should be positive integer */
	if (Noofintervals <= 0) {
		printf("\n\t\t Number of intervals should be positive integer\n");
		exit(1);
	}
	totalsum = 0.0;

 	gettimeofday(&TimeValue_Start, &TimeZone_Start);

	h = 1.0 / Noofintervals;

        /* set the number of threads */ 
	omp_set_num_threads(Noofthreads);
	/*
	 * OpenMP Parallel Directive With Private Clauses And Critical
	 * Section
	 */
	#pragma omp parallel for private(x)
	for (i = 1; i < Noofintervals + 1; i = i+1) {
		x = h * (i + 0.5);
               /*printf("the thread id is %d with iteration %d ",omp_get_thread_num(),i);*/
		#pragma omp critical
		totalsum = totalsum + 4.0/(1.0 + x * x);
	} /* All thread join Master thread */
	totalsum = totalsum * h;
	gettimeofday(&TimeValue_Final, &TimeZone_Final);
       

        time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
        time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
 
	time_overhead = (time_end - time_start)/1000000.0;

	/*printf("\n\t\t Calculated PI :  \t%1.15lf  \n\t\t Error : \t%1.16lf\n", totalsum, fabs(totalsum - PI));*/
	printf("\n\t\t Calculated PI               : %1.15lf",totalsum );
	printf("\n\t\t Time in Seconds (T)         : %lf",time_overhead);
        printf("\n\n\t\t   ( T represents the Time taken for computation )");
        printf("\n\t\t..........................................................................\n");
}
