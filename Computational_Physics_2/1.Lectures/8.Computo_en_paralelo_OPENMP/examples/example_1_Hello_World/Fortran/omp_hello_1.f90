! https://curc.readthedocs.io/en/latest/programming/OpenMP-Fortran.html
! Compile
! $ gfortran -fopenmp -o out example_2_OpenMP_Hello_World_Subroutine.f90 
! Set environment variable 
! $ export OMP_NUM_THREADS=16
! Execute 
! $ ./out 
! How do we parallelize the print statement? We parallelize it with omp parallel !
! The !$OMP PARALLEL and !$OMP END PARALLEL directives creates a section of code that is run from all available threads.

program parallel_stored_hello
  use omp_lib
  implicit none

!$omp parallel
    print *, "hello from process: ", omp_get_thread_num()
!$omp end parallel

end program
