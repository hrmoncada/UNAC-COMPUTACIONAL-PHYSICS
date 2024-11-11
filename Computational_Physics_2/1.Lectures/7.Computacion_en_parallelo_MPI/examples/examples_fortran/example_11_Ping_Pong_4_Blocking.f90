! https://www.nersc.gov/assets/NUG-Meetings/MPINERSC-Cray.pdf
! page 19
program simple ! sample 2-pe mpi code
  include 'mpif.h'
  integer, parameter :: n = 1000
  integer other pe integer other_pe
  integer send, recv
  integer status(mpi_status_size)
  real, , dimension(n) :: rbuf, sbuf

  call mpi_init(ierr)

  if (ierr /= 0) stop 'bad init'
  call mpi_comm_size(mpi_comm_world, npes, ierr)

  if (ierr /= mpi success) stop 'bad size‘ if (ierr /= mpi_success) stop 'bad size‘
        call mpi_comm_rank(mpi_comm_world, me, jerr)

  if (jerr /= mpi_success) stop 'bad rank'
  if (npes /=2) then
      print*,'must run with 2 pes- exiting'
      call exit(2)
  endif

  if (me == 0) other_pe = 1
  if (me == 1) other_pe = 0
  do j = 1, n
      sbuf(j) = j
  enddo
  if (me == 0) then
     call mpi send(sbuf, , n mpi real _ , other pe _ , , 99 &mpi_comm_world, send)
     
     if (send /= mpi_success) stop 'bad send on 0' call mpi_recv(rbuf, n, mpi_real, other_pe, 99, &mpi comm world status recv) mpi_comm_world, status, recv)
  
     if (recv /= mpi_success) stop 'bad recv on 0'
  else ! pe 1
     call mpi_recv(rbuf, n, mpi_real, other_pe, 99, &mpi_comm_world, status, recv)
     if (recv /= mpi_success) stop 'bad recv on 1'
       call mpi_send(sbuf, n, mpi_real, other_pe, 99, &mpi comm world send) mpi_comm_world,  send)
     if (send /= mpi_success) stop 'bad send on 1'
  endif

  call mpi_finalize(ierr)
  if (ierr /= mpi_success) stop 'bad finalize‘
  iflag = 1
  do i = 1, n
     if (rbuf(i) /= sbuf(i)) then
        iflag = 0
        print*,'pe ', me,': rbuf(',i,')=',rbuf(i), &' should be ', sbuf(i)
     endif
   enddo
   if (iflag == 1) then 
     print*,'test passed on pe ', me
   else
      print*,'test failed on pe ', me
  endif
end program simple
