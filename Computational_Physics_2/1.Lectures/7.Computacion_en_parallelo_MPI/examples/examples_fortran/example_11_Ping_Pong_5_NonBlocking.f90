! https://www.archer.ac.uk/training/course-material/2017/09/mpi-york/slides/L07-nonblocking.pdf
! page 17

program arraypractice
  use mpi
  implicit none
  !include 'mpif.h'
  integer :: num_procs    ! Number of processes
  integer :: my_rank      ! My process rank
  integer :: ierr         ! All MPI fortran call return an error message 
  integer request
  integer, dimension(MPI_STATUS_SIZE) :: status
  !integer :: status(MPI_STATUS_SIZE) ! The status argument must be declared as an array of size MPI_STATUS_SIZE, as in integer status(MPI_STATUS_SIZE)
  integer :: recv_array, send_array
  
  call MPI_Init (ierr)                                ! Initialize the MPI environment, starts MPI
  call MPI_Comm_rank (MPI_COMM_WORLD, my_rank, ierr)  ! Get current process' "ID" number (rank) */
  call MPI_Comm_size (MPI_COMM_WORLD, num_procs, ierr)! Get total number of processes */
  
  if (my_rank == 0) then
     CALL MPI_ISSEND(send_array, 10, MPI_INTEGER, 1, tag, MPI_COMM_WORLD, request, ierror)
     CALL Do_something_else_while Issend_happens()
! now wait for send to complete
     CALL MPI_Wait(request, status, ierror)
  else if (my_rank == 1) then
     CALL MPI_IRECV(recv_array, 10, MPI_INTEGER, 0, tag, MPI_COMM_WORLD, request, ierror)
     CALL Do_something_else_while Irecv_happens()
! now wait for receive to complete
     CALL MPI_Wait(request, status, ierror)
  endif
  
  call MPI_Finalize(ierr)       ! Finalize the MPI environment
end
