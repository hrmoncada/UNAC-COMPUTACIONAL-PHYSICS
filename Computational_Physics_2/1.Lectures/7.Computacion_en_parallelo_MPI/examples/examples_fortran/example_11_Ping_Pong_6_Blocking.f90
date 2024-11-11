! https://www.nics.tennessee.edu/files/pdf/MPI_WORKSHOP/sendrecv.f.soln
program sendrecv
  use mpi
  implicit none
  !include 'mpif.h'
  integer, parameter :: MAX_STRING = 17
  character* (MAX_STRING) message  ! String storing message,  char buffer
  !character(17) message
  !character* 17 message
  integer :: num_procs    ! Number of processes
  integer :: my_rank      ! My process rank
  integer :: ierr         ! All MPI fortran call return an error message 
  integer :: status(MPI_STATUS_SIZE) ! The status argument must be declared as an array of size MPI_STATUS_SIZE, as in integer status(MPI_STATUS_SIZE)

  integer :: ntag
  
  ntag = 100

!----------------
! Initialize MPI *
!----------------
  call MPI_Init (ierr)                                ! Initialize the MPI environment, starts MPI
  call MPI_Comm_rank (MPI_COMM_WORLD, my_rank, ierr)  ! Get current process' "ID" number (rank) */
  call MPI_Comm_size (MPI_COMM_WORLD, num_procs, ierr)! Get total number of processes */

!-------------------------------------------------------*
! Process 0 sends a message to process 1*
!-------------------------------------------------------*
   if (my_rank .eq. 0) then
        message = '"Hello, World!!!"'
        call MPI_Send(message,  & ! (I) initial address of send buffer (choice) 
                 len(message),  & ! (I) number of elements in send buffer (nonnegative integer)
                MPI_CHARACTER,  & ! (I) datatype of each send buffer element (handle) 
                            1,  & ! (I) rank of destination (integer) 
                         ntag,  & ! (I) message tag (integer) 
                MPI_COMM_WORLD, & ! (I) communicator (handle) 
                          ierr)   ! (O) error variable (integer)
   endif
!------------------------------------------------------------*
! Process 1 receives a message from process 0 and outputs the result                     *
!------------------------------------------------------------*
  if (my_rank .eq. 1) then
      call MPI_Recv(message,  & ! (O) initial address of receive buffer (choice) 
               len(message),  & ! (I) maximum number of elements in receive buffer (integer)
              MPI_CHARACTER,  & ! (I) datatype of each receive buffer element (handle)
                          0,  & ! (I) rank of source (integer)
                       ntag,  & ! (I) message tag (integer)
             MPI_COMM_WORLD,  & ! (I) communicator (handle) 
                     status,  & ! (O) status object (Status)
                       ierr)    ! (O) error variable (integer)
                       
      !print *, 'Process',my_rank, ':', message
      print *," "
      print '("Rank ",I2, &
              " : Receive message : ",A, &
              " send from Rank ",I2, &
              " with tag ",I3," ")', my_rank, message, status(MPI_SOURCE), status(MPI_TAG)
  endif

!------------------------------*
! Finalize MPI *
!------------------------------*
     call MPI_Finalize(ierr)       ! Finalize the MPI environment

end program
