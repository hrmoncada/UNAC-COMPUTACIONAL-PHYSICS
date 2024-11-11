PROGRAM main
   USE mpi
   IMPLICIT NONE
   INTEGER, parameter :: N=1001
   INTEGER :: ierr, i, rank, nprocs
   INTEGER :: nstart, nstop, npart, ncount, nrem
   DOUBLE PRECISION, allocatable :: vec(:)
   DOUBLE PRECISION :: local_sum, total_sum

   CALL MPI_INIT(ierr)
   CALL MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierr)
   CALL MPI_Comm_size(MPI_COMM_WORLD, nprocs, ierr)

   ncount = N/nprocs
   nrem = MOD(N,nprocs)

   IF (rank < nrem) THEN
      nstart = rank * (ncount + 1)
      nstop = nstart + ncount
   ELSE
     nstart = rank * ncount + nrem
     nstop = nstart + (ncount - 1)
   END IF

   npart = nstop-nstart+1

   allocate(vec(npart))
   
   DO i=1,npart
     vec(i) = 1.0D0
   END DO
 
   local_sum = 0.0D0

   DO i=1,npart
      local_sum = local_sum + vec(i)
   END DO

   WRITE(*,’(A,I3,A,F15.8)’) "[",rank,"] part : ",local_sum

   CALL MPI_BARRIER(MPI_COMM_WORLD,ierr)
   CALL MPI_REDUCE(local_sum, total_sum, 1, MPI_DOUBLE, MPI_SUM, 0 , MPI_COMM_WORLD, ierr)

   IF (rank.eq.0) THEN
      WRITE(*,*) "Sum : ", total_sum
   END IF

   deallocate(vec)

   CALL MPI_FINALIZE(ierr)

END PROGRAM
