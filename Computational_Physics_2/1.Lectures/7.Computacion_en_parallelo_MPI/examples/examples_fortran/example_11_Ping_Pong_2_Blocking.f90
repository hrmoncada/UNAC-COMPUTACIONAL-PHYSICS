! https://stackoverflow.com/questions/47385834/mpi-recv-only-recieving-half-of-the-data-sent-by-mpi-send-utterly-confused
! Note: error notation in declareing the arrays
! real, denote 32-bit single-precision numbers.
! MPI_REAL, denote 32-bit single-precision numbers.
! real*8, denotes 64-bit double-precision numbers 
! MPI_DOUBLE_PRECISION or MPI_REAL8, denotes 64-bit double-precision numbers 
! If you declare real*8 on (f, g) and MPI_Real on (MPI_Send and MPI_Recv),
! MPI sends the first half of the data only. Therefore, either get rid of *8 in real*8 to use
! single precision or replace MPI_REAL with MPI_DOUBLE_PRECISION or MPI_REAL8 to use double precision.

program arraypractice
  use mpi
  implicit none
  !include 'mpif.h'      ! Include MPI header file that contains the library’s API
  integer :: num_procs   ! Number of processes
  integer :: my_rank     ! My process rank
  integer :: ierr        ! All MPI fortran call return an error message 
  integer :: i, ntag
  integer :: status(MPI_STATUS_SIZE) ! The status argument must be declared as an array of size MPI_STATUS_SIZE, as in integer status(MPI_STATUS_SIZE)
  integer dcount
  real  f(10), g(10)  ! 1D arrays, 
  
  ntag = 10

!----------------
! Initialize MPI *
!----------------  
  call MPI_Init (ierr)   ! Initialize the MPI environment, starts MPI */
  call MPI_Comm_rank (MPI_COMM_WORLD, my_rank, ierr)  ! Get current process' "ID" number (rank)
  call MPI_Comm_size (MPI_COMM_WORLD, num_procs, ierr)! Get total number of processes
  
!-------------------------------------------------------*
! Process 0 sends a message to process 1*
!-------------------------------------------------------*  
  if(my_rank == 0) then
      print *," "
      print *,"Set arrays "
      do i = 1, 10
         f(i) = float(i)
         print '(" f(",I2,") = ",F6.1 ,X,","X,"g(",I2,") = ",F6.1," ")', i, f(i), i, g(i)
      enddo
      print *," "
  endif

  if(my_rank == 0) then
        call MPI_Send(f,  & ! (I) initial address of send buffer (choice) 
                      6,  & ! (I) number of elements in send buffer (nonnegative integer) 
               MPI_Real,  & ! (I) datatype of each send buffer element (handle) 
                      1,  & ! (I) rank of destination (integer)  
                   ntag,  & ! (I) message tag (integer)  
         MPI_COMM_WORLD,  & ! (I) communicator (handle) 
                   ierr)    ! (O) error variable (integer)
  endif
  
!------------------------------------------------------------*
! Process 1 receives a message from process 0 and outputs the result                     *
!------------------------------------------------------------* 
  if(my_rank == 1) then
         call MPI_Recv(g,  & ! (O) initial address of receive buffer (choice) 
                       6,  & ! (I) maximum number of elements in receive buffer (integer)
                MPI_Real,  & ! (I) datatype of each receive buffer element (handle)
                       0,  & ! (I) rank of source (integer)
                    ntag,  & ! (I) message tag (integer)
          MPI_COMM_WORLD,  & ! (I) communicator (handle)  
                  status,  & ! (O) status object (Status)
                    ierr)    ! (O) error variable (integer)
                    
! MPI_Get_count:  Gets the number of "top level" elements 
     call MPI_get_count(status,  & ! (I) return status of receive operation (Status)
                      MPI_Real,  & ! (I) datatype of each receive buffer element (handle)
                        dcount,  & ! (O) number of received elements (integer) 
                          ierr)    ! (O) error variable (integer)
     !print '(" Number of receive elements = ",I2," ")', dcount
     
     print *," "
     print '("Rank ",I2, &
              " : Receive  : ",I2," numbers" &
              " send from Rank ",I2, &
              " with tag ",I3," ")', my_rank, dcount, status(MPI_SOURCE), status(MPI_TAG)
     print *,""
     do i = 1, 6
        !print *,f1(i)
        print '(" g(",I2,") = ",F6.2," ")', i, g(i)
     enddo
  endif
!------------------------------*
! Finalize MPI *
!------------------------------* 
  call MPI_Finalize(ierr)           !Finalize the MPI environment 
end program
