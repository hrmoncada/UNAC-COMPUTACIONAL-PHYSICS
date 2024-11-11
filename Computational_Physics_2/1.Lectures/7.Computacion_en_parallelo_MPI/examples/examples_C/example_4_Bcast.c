#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

   int nprocs,rang;
   int n;

   MPI_Init(&argc,&argv);
   MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
   MPI_Comm_rank(MPI_COMM_WORLD, &rang);

   if (rang==0) {
     FILE *fp = fopen("data.txt", "r");
     fscanf(fp, "%d", &n);
     fclose(fp);
   }

   MPI_Bcast(&n,1,MPI_INTEGER,0,MPI_COMM_WORLD);

   printf("Process %d has received %d \n",rang,n);

   MPI_Finalize();

   return 0;
}
