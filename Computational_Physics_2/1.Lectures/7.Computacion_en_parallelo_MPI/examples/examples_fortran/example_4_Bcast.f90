! https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
PROGRAM bcast
  USE mpi
  IMPLICIT NONE

  INTEGER :: n,nprocs,rang
  INTEGER :: ierr = 0
  INTEGER, PARAMETER :: idat=91

  CALL MPI_INIT(ierr)
  CALL MPI_COMM_SIZE(MPI_COMM_WORLD, nprocs, ierr)
  CALL MPI_COMM_RANK(MPI_COMM_WORLD, rang, ierr)

  IF (rang.eq.0) THEN
    OPEN(unit=idat,file='data.txt')
    READ(idat,*) n
    CLOSE(idat)
  END IF

  CALL MPI_BCAST(n,1,MPI_INT,0,MPI_COMM_WORLD,ierr)

  print *,'Process',rang,' has received ',n

  CALL MPI_FINALIZE(ierr)

END PROGRAM bcast
