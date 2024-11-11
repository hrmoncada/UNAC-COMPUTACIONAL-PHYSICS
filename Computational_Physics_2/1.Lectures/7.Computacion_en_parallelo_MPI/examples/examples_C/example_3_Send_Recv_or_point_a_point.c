/*
https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
$ mpicc example_3_Send_Recv_or_point_a_point.c -o out
$ mpirun -np 4 ./out
Enter integer number:
100
Slave 1 has received n=100 from 0
Slave 2 has received n=100 from 0
Slave 3 has received n=100 from 0
Master 0 received from slave 1: 100
Master 0 received from slave 2: 200
Master 0 received from slave 3: 300

*/

#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rang,nprocs;
    int master,tagm,tagr;
    int n,i;

    MPI_Status status;
    MPI_Init(&argc,&argv);

    master = 0;
    tagm = 101;
    tagr = 201;

    MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&rang);

    if (rang == master) {
       printf("Enter integer number:\n");
       scanf("%d",&n);

       for (i = 1; i < nprocs; i++) {
          MPI_Send(&n,1,MPI_INT,i,tagm,MPI_COMM_WORLD);
       }

       for (i = 1; i < nprocs; i++) {
           MPI_Recv(&n,1,MPI_INT,i,tagr,MPI_COMM_WORLD,&status);
           printf("Master %d received from slave %d: %d\n",rang, i, n);
       }
    } else {
      MPI_Recv(&n,1,MPI_INT,master,tagm,MPI_COMM_WORLD,&status);
      
      printf("Slave %d has received n=%d from %d\n",rang,n,master);
      n = n * rang;

      MPI_Send(&n,1,MPI_INT,master,tagr,MPI_COMM_WORLD);
    }

    MPI_Finalize();
}
