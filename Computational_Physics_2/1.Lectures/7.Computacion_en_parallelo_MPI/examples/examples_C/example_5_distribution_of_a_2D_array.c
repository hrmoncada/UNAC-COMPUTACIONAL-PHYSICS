/*https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
*/
#include "mpi.h"
#include <stdio.h>
#define SIZE_X 5
#define SIZE_Y 4

int main(int argc, char *argv[]) {
   int numtasks, rank, sendcount, recvcount, source;
   float sendbuf[SIZE_Y][SIZE_X] = {
                                     {1.0, 2.0, 3.0, 4.0, 4.5},
				     {5.0, 6.0, 7.0, 8.0, 8.5},
                                     {9.0, 10.0, 11.0, 12.0, 12.5},
				     {13.0, 14.0, 15.0, 16.0, 16.5} };
   float recvbuf[SIZE_X];
   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

   if (numtasks == SIZE_Y) {
// define source task and elements to send/receive, then perform collective scatter
       source = 1;
       sendcount = SIZE_X;
       recvcount = SIZE_X;

       MPI_Scatter(sendbuf,sendcount,MPI_FLOAT,recvbuf,recvcount, MPI_FLOAT,source,MPI_COMM_WORLD);

       printf("rank= %d Results: %f %f %f %f %f\n",rank,recvbuf[0], recvbuf[1],recvbuf[2],recvbuf[3],recvbuf[4]);
   } else
        printf("Must specify %d processors. Terminating.\n",SIZE_Y);

   MPI_Finalize();

   return 0;
}
