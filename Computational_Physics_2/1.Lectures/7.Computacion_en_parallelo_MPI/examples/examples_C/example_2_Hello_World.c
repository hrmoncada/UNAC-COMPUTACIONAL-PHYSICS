/*https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
$ mpicc example_2_Hello_World.c -o out
$ mpirun -np 4 ./out
Hello! I am process 0 of 4 on lola.
Hello! I am process 1 of 4 on lola.
Hello! I am process 2 of 4 on lola.
Hello! I am process 3 of 4 on lol
*/
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    int numtasks, rank, reslen, rc;
    char hostname[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Get_processor_name(hostname, &reslen);

    printf("Hello! I am process %d of %d on %s.\n",rank,numtasks,hostname);

    MPI_Finalize();
}
