!https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
program scatter
  include 'mpif.h'

  integer SIZE_X,SIZE_Y

  parameter(SIZE_X=5,SIZE_Y=4)
    
  integer numtasks, rank, sendcount, recvcount, source, ierr

  real*4 sendbuf(SIZE_X,SIZE_Y), recvbuf(SIZE_X)
  data sendbuf /1.0, 2.0, 3.0, 4.0, 4.5, &
               5.0, 6.0, 7.0, 8.0, 8.5, &
               9.0, 10.0, 11.0, 12.0, 12.5, &
               13.0, 14.0, 15.0, 16.0, 16.5/

  call MPI_INIT(ierr)
  call MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierr)
  call MPI_COMM_SIZE(MPI_COMM_WORLD, numtasks, ierr)

  if (numtasks .eq. SIZE_Y) then

     source = 1
     sendcount = SIZE_X
     recvcount = SIZE_X

     call MPI_SCATTER(sendbuf, sendcount, MPI_REAL, recvbuf, recvcount, MPI_REAL, source, MPI_COMM_WORLD, ierr)

     print *, 'rank= ',rank,' Results: ',recvbuf

  else
     print *, 'Must specify',SIZE_Y,' processors. Terminating.'
  endif

  call MPI_FINALIZE(ierr)

end


