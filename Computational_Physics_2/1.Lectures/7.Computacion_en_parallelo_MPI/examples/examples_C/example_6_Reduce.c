/*
https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
*/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i, N;
  int nprocs, rank;

  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  
  double *vec;
  double local_sum,sum;

  N=1001;   

  int count = N/nprocs;
  int remainder = N%nprocs;
  int start, stop;

  if (rank < remainder) {
     start = rank * (count + 1);
     stop = start + count;
  } else {
     start = rank * count + remainder;
     stop = start + (count - 1);
  }

  int npart = stop-start+1;
  vec = malloc(sizeof(double)*npart);
  
  for (i=0; i<npart; i++) {
    vec[i] = 1.0;
  }

  local_sum = 0.0;

  for (i=0; i<npart; i++) {
     local_sum += vec[i];
  }

  printf("[ %d ] part : %g\n",rank,local_sum);

  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Reduce(&local_sum,&sum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
 
  if (rank == 0) {
    printf("Sum : %g\n",sum);
  }

  MPI_Finalize();
  return 0;
}
