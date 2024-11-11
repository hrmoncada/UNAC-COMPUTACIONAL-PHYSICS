! https://computing.llnl.gov/tutorials/mpi/     
program ringtopo
   include 'mpif.h'

   integer numtasks, rank, next, prev, buf(2), tag1, tag2, ierr
   integer reqs(4)   ! required variable for non-blocking calls 
   integer stats(MPI_STATUS_SIZE,4)   ! required variable for WAITALL routine 
   tag1 = 1
   tag2 = 2

   call MPI_INIT(ierr)
   call MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierr)
   call MPI_COMM_SIZE(MPI_COMM_WORLD, numtasks, ierr)

   ! determine left and right neighbors 
   prev = rank - 1
   next = rank + 1
   if (rank .eq. 0) then
      prev = numtasks - 1
   endif
   if (rank .eq. numtasks - 1) then
      next = 0
   endif

   ! post non-blocking receives and sends for neighbors 
   call MPI_IRECV(buf(1), 1, MPI_INTEGER, prev, tag1, MPI_COMM_WORLD, reqs(1), ierr)
   call MPI_IRECV(buf(2), 1, MPI_INTEGER, next, tag2, MPI_COMM_WORLD, reqs(2), ierr)

   call MPI_ISEND(rank, 1, MPI_INTEGER, prev, tag2, MPI_COMM_WORLD, reqs(3), ierr)
   call MPI_ISEND(rank, 1, MPI_INTEGER, next, tag1, MPI_COMM_WORLD, reqs(4), ierr)

      ! do some work while sends/receives progress in background

   ! wait for all non-blocking operations to complete 
   call MPI_WAITALL(4, reqs, stats, ierr);

      ! continue - do more work

   call MPI_FINALIZE(ierr)

   end
