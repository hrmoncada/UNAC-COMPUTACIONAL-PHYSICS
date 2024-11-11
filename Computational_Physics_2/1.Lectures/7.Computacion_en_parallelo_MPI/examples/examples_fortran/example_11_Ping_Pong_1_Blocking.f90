
program ping
   !use mpi
   implicit none
   include 'mpif.h'         ! Include MPI header file that contains the library’s API

   integer :: num_procs   ! Number of processes
   integer :: my_rank     ! My process rank
   integer :: ierr        ! All MPI fortran call return an error message 
   integer :: destination, source, counter, tag
   integer :: status(MPI_STATUS_SIZE) ! The status argument must be declared as an array of size   MPI_STATUS_SIZE, as in integer status(MPI_STATUS_SIZE). It is required variable for receive routines
   character :: input_msg, output_msg
   
   output_msg = 'x'
   tag = 1

   call MPI_Init (ierr)                                ! Initialize the MPI environment, starts MPI
   call MPI_Comm_rank (MPI_COMM_WORLD, my_rank, ierr)  ! Get current process' "ID" number (rank) */
   call MPI_Comm_size (MPI_COMM_WORLD, num_procs, ierr)! Get total number of processes */

! task 0 sends to task 1 and waits to receive a return message
   if (my_rank .eq. 0) then

      destination = 1  ! rank of detination
      source = 1       ! rank of source
      call MPI_SEND(output_msg, 1, MPI_CHARACTER, destination, tag, MPI_COMM_WORLD, ierr)
      call MPI_RECV(input_msg, 1, MPI_CHARACTER, source, tag, MPI_COMM_WORLD, status, ierr)
      
! task 1 waits for task 0 message then returns a message
   else if (my_rank .eq. 1) then
      destination = 0 ! rank of detination
      source = 0      ! rank of source
      call MPI_RECV(input_msg, 1, MPI_CHARACTER, source, tag, MPI_COMM_WORLD, status, ierr)
      call MPI_SEND(output_msg, 1, MPI_CHARACTER, destination, tag, MPI_COMM_WORLD, ierr)

   endif

! MPI_Get_count:  Gets the number of "top level" elements    
! Query recieve Stat variable and print message details
   call MPI_GET_COUNT(status, MPI_CHARACTER, counter, ierr)
   print *,""
   print '(" Rank ",I2," : Received ",I2, &
               " char(s) from Rank ",I2, &
               " with tag ",I2," ")', my_rank, counter, status(MPI_SOURCE), status(MPI_TAG)

   call MPI_Finalize(ierr)       ! Finalize the MPI environment

end program


