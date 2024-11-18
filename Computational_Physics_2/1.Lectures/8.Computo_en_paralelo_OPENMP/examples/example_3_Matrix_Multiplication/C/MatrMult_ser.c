#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif

int main(  int argc, char *argv[] )
{ 

   double *A, *B, *C, *tC;
   int L, M, N, L0, L1;
   double cput2, cput1, wall2, wall1;

   int i, j, k, t, st;
   double v, rmin, rmax;

/*  OMP variables */
   int ierr, my_rank, numprocs;

      fprintf(stdout,"Input dimensions of matrices  L, M, N:\n");
      fscanf(stdin,"%d, %d, %d",&L, &M, &N);
      fprintf(stdout," Matrices dimensions are: %d, %d, %d\n",L,M,N);

         A = (double*) malloc(sizeof((double)1.0)*L*M);
         B = (double*) malloc(sizeof((double)1.0)*N*M);
         C = (double*) malloc(sizeof((double)1.0)*L*N);
         if ( A == NULL || B == NULL || C == NULL ) {
            fprintf(stderr,"Error allocating matrices \n");
      	    return(-1);
         }


   /*  Initializations */
   // Insert parallel region, pay attention to  shared or private variables
   

   	// Do it in parallel 	
   	   for ( i = 0; i < L*M; i++ ) A[i] = 0.0;
   	
   	
   	// Do it in parallel
   	   for ( i = 0; i < N*M; i++ ) B[i] = 0.0;
   	  
      
   	// Do it in parallel
   	   for ( i = 0; i < L*N; i++ ) C[i] = 0.0;
   	  

   	// Do it in parallel
   	   for ( i = 0; i < L; i++ ) {
   	   	   for ( k = 0; k < M; k++ ) {
   	   	   	   A[ i*M + k] = (double)(i-k) / (double)(i+k+1);
   	   	   }
   	   }
   
   	// Do it in parallel
   	  for ( j = 0; j < N; j++ ) {
   	  	  for ( k = 0; k < M; k++ ) {
   	  	  	  B[ k*N + j ] = 0.01 * (double)(k-j) / (double)(k+j+1);
   	  	  }
   	  }
   // Close parallel region
   // This statement is executed only by master thread if openmp is defined
   //wall1 = omp_get_wtime();
   

   /* Compute local */
   
   // Insert parallel region, pay attention to  shared or private variables
   
   // This statement is executed only if openmp is defined
   //my_rank = omp_get_thread_num();
   //numprocs = omp_get_num_threads();
   
   my_rank = 0; numprocs = 1;
   
   ierr = intervals(L,&L0,&L1,numprocs,my_rank);
   
   /*  Compute multiplication */
   // This statement is executed by all threads but only one at a time
      printf("Process %d of %d computes C(:,%d:%d) \n",my_rank,numprocs,L0,L1-1);
      
      for ( j = 0; j < N; j++ ) {
         for ( i = L0; i < L1; i++ ) {
            C[ i*N + j ] = 0.0;
            for ( k = 0; k < M; k++ ) {
               C[ i*N + j ] = C[ i*N + j ] + A[ i*M + k ] * B[ k*N + j ];
            }
         }
      }
   // Close parallel region
   
   // This statement is executed only by master thread if openmp is defined
     // wall2 = omp_get_wtime();
   
      /* Compare results */ 
      tC = (double*) malloc(sizeof((double)1.0)*L*N);
      if ( tC == NULL ) {
         fprintf(stderr," Process %d: Error allocating matrix tC \n",my_rank);
      }

      for ( i = 0; i < L; i++ ) {
         for ( k = 0; k < M; k++ ) {
            A[ i*M + k] = (double)(i-k) / (double)(i+k+1);
         }
      }
   
      for ( j = 0; j < N; j++ ) {
         for ( i = 0; i < L; i++ ) {
            tC[ i*N + j ] = 0.0;
            for ( k = 0; k < M; k++ ) {
               tC[ i*N + j ] = tC[ i*N + j ] + A[ i*M + k ] * B[ k*N + j ];
            }
         }
      }

      rmin = rmax = tC[0] - C[0];
      for ( j = 0; j < N; j++ ) {
         for ( i = 0; i < L; i++ ) {
            v = tC[ i*N + j ] - C[ i*N + j ];
            if ( v < rmin ) {
               rmin = v;
            }
            if ( v > rmax ) {
               rmax = v;
            }
         }
      }

      fprintf(stderr," Check results: rmin, rmax = %f, %f\n",rmin,rmax);
      
      fprintf(stdout,"Elapsed time is %lf \n",(wall2-wall1));
      	   	   
  
   return(0);
}

int intervals(int length, int* start, int* end, int segments, int n)
{
    int delta;

    delta = ( length + (segments - 1) ) / segments;
    *start = delta * n; *end = delta * ( n + 1);
    if ( *end > length ) *end = length;
   
   return(0);
}

