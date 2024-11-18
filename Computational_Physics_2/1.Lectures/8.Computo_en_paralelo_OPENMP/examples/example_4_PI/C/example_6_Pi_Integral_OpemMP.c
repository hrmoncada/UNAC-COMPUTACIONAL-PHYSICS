/*
https://www.olcf.ornl.gov/tutorials/monte-carlo-pi/
*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
 
int main(int argc, char* argv[])
{
    int niter = 1000000;            //number of iterations per FOR loop
    double x,y;                     //x,y value for the random coordinate
    int i;                          //loop counter
        int count=0;                //Count holds all the number of how many good coordinates
    double z;                       //Used to check if x^2+y^2<=1
    double pi;                      //holds approx value of pi
        int numthreads = 16;
 
    #pragma omp parallel firstprivate(x, y, z, i) shared(count) num_threads(numthreads)
    {
        srandom((int)time(NULL) ^ omp_get_thread_num());    //Give random() a seed value
        for (i=0; i<niter; ++i)              //main loop
        {
            x = (double)random()/RAND_MAX;      //gets a random x coordinate
            y = (double)random()/RAND_MAX;      //gets a random y coordinate
            z = sqrt((x*x)+(y*y));          //Checks to see if number is inside unit circle
        if (z<=1)
        {
                ++count;            //if it is, consider it a valid random point
        }
    }
        //print the value of each thread/rank
    }
        pi = ((double)count/(double)(niter*numthreads))*4.0;
        printf("Pi: %f\n", pi);
 
    return 0;
}
