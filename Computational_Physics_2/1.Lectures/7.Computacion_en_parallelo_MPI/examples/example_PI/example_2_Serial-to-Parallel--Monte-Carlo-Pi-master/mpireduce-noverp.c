#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mpi.h"

int main(int argc, char* argv[])
{
	int niter = 1000000;
	int myid;						//hold's process's rank id
	double x,y;						//x,y value for the random coordinate
	int i;
        int count=0;						//Count holds all the number of how many good coordinates
	double z;						//Used to check if x^2+y^2<=1
	double pi;						//holds approx value of pi
	int numnodes;
	int reducedcount;					//total number of "good" points from all nodes
	int reducediters; 					// total number of actual iterations 

	MPI_Init(&argc, &argv);					//Start MPI
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);			//get rank of node's process
	MPI_Comm_size(MPI_COMM_WORLD, &numnodes);
	int myiters = XXXXX

	srand48(time(NULL)+myid);

	for(i = 0; i < XXXXXX ; i++)
	{
		x = (double)drand48();			//gets a random x coordinate
		y = (double)drand48();			//gets a random y coordinate
		z = ((x*x)+(y*y));			//Checks to see if number in inside unit circle
		if (z<=1)
		{
			count++;			//if it is, consider it a valid random point	
		}	
	}

	/* Now we can reduce the values to master */

	MPI_Reduce(&count, &reducedcount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce( XXXX )
		
	if (myid == 0)						//if root process
	{      
		//p = 4(m/n)
		pi = ((double)reducedcount/(double) XXXX )*4.0;	
		printf("Pi: %f\n", pi);			
	}
	MPI_Finalize();						//Close the MPI instance
	return 0;
}
