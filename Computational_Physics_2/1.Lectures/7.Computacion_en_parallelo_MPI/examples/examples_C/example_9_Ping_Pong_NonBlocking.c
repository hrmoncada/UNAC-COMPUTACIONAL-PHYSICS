/*
 https://www.archer.ac.uk/training/course-material/2017/09/mpi-york/slides/L07-nonblocking.pdf
 page 16
 */
#include <stdio.h>
#include <mpi.h>

int main (int argc, char* argv[]) {
   int num_procs;                                 /* Number of processes  */
   int my_rank;                                   /* My process rank  */
   int recv_array, send_array
   int request;
   
   MPI_Init (&argc, &argv);                         /* Initialize the MPI environment, starts MPI */
   MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);        /* Get current process' "ID" number (rank) */
   MPI_Comm_size (MPI_COMM_WORLD, &num_procs);      /* Get total number of processes */

   MPI_Request request;
   MPI_Status status;

   if (rank == 0) {
     MPI_Issend(send_array, 10, MPI_INT, 1, tag, MPI_COMM_WORLD, &request);
     Do_something_else_while Issend_happens();
// now wait for send to complete
    MPI_Wait(&request, &status);
   } else if (rank == 1) {
     MPI_Irecv(recv_array, 10, MPI_INT, 0, tag, MPI_COMM_WORLD, &request);
     Do_something_else_while Irecv_happens();
// now wait for receive to complete;
     MPI_Wait(&request, &status);
   }
   
   MPI_Finalize();                                /* Finalize the MPI environment */

  return 0;
}
