!https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
! $ mpif90 example_2_Hello_World.f90 -o out
! $ mpirun -np 4 ./out
!Hello! I am process  0 of  4 on lola.
!Hello! I am process  1 of  4 on lola.
!Hello! I am process  2 of  4 on lola.
!Hello! I am process  3 of  4 on lola.

PROGRAM hello
USE mpi
IMPLICIT NONE

INTEGER :: numtasks, rank, reslen, ierr = 0
CHARACTER(MPI_MAX_PROCESSOR_NAME) :: hostname

CALL MPI_INIT(ierr)
CALL MPI_COMM_SIZE(MPI_COMM_WORLD, numtasks, ierr)
CALL MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierr)
CALL MPI_GET_PROCESSOR_NAME(hostname, reslen, ierr)

WRITE(*, '(2A,I2,A,I2,3A)') 'Hello! ', 'I am process ', rank,  ' of ', numtasks, ' on ', hostname(1:reslen), '.'

CALL MPI_FINALIZE(ierr)

END PROGRAM hello
