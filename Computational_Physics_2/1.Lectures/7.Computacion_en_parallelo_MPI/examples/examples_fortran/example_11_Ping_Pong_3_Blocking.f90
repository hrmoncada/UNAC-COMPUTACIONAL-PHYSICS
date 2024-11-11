!https://www.bu.edu/tech/files/2016/09/Intro_MPI.pdf
!A Fortran example: send and receive a number between two processes

program arraypractice
  use mpi
  implicit none
  !include 'mpif.h'
  integer :: num_procs    ! Number of processes
  integer :: my_rank      ! My process rank
  integer :: ierr         ! All MPI fortran call return an error message 
  integer :: status(MPI_STATUS_SIZE) ! The status argument must be declared as an array of size MPI_STATUS_SIZE, as in integer status(MPI_STATUS_SIZE)
  integer :: number_to_receive, number_to_send
  integer :: ntag
 
  ntag = 10
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
      number_to_send = 36
      call MPI_Send( number_to_send,  & ! (I) initial address of send buffer (choice) 
                                  1,  & ! (I) number of elements in send buffer (nonnegative integer)
                        MPI_Integer,  & ! (I) datatype of each send buffer element (handle) 
                                  1,  & ! (I) rank of destination (integer)  
                               ntag,  & ! (I) message tag (integer)  
                     MPI_COMM_WORLD,  & ! (I) communicator (handle) 
                               ierr)    ! (O) error variable (integer)
!------------------------------------------------------------*
! Process 1 receives a message from process 0 and outputs the result                     *
!------------------------------------------------------------*                               
  elseif (my_rank .eq. 1) then
      call MPI_Recv( number_to_receive, & ! (O) initial address of receive buffer (choice) 
                                     1, & ! (I) maximum number of elements in receive buffer (integer)
                           MPI_Integer, & ! (I) datatype of each receive buffer element (handle)
                                     0, & ! (I) rank of source (integer)
                                  ntag, & ! (I) message tag (integer)
                        MPI_COMM_WORLD, & ! (I) communicator (handle)  
                                status, & ! (O) status object (Status)
                                  ierr)   ! (O) error variable (integer)
      print *,""                            
      !print *,'number received is:', number_to_receive
      print '(" Rank ",I2,&
              " : Receive the number ",I2, &
              " send from Rank ",I2, &
              " with tag ",I2," ")', my_rank, number_to_receive, status(MPI_SOURCE), status(MPI_TAG)
  endif

!------------------------------*
! Finalize MPI *
!------------------------------*  
  call MPI_Finalize(ierr)       ! Finalize the MPI environment
end
