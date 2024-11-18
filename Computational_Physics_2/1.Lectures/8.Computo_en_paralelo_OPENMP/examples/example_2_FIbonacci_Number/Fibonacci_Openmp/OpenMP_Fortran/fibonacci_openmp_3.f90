! https://luiarthur.github.io/assets/ams250/notes/notes5.pdf
!page 55
!
! gfortran -fopenmp -o out fibonacci_openmp_3.f90
! export OMP_NUM_THREADS=8
! ./out 40
!Fibonacci number generator.
!    Target number: 40
!    Number of threads: 8
!fibonacci(40) = 102334155

recursive integer function fibonacci(n) result(res)
  integer :: i, j
  integer, intent(in) :: n
  
  if (n < 2) then
    res = n
  else 
       !$omp task shared(i) firstprivate(n)
       i = fibonacci(n-1)
       !$omp end task 
       
       !$omp task shared(j) firstprivate(n)
       j = fibonacci(n-2)
       !$omp end task 
       
       !$omp taskwait
       res = i + j
   end if
end function

program fibonacci_num
   use omp_lib
   implicit none
   integer :: fibonacci      ! call the function
   character(60) :: argument
   integer :: n, nthreads, num_arguments
   
   !first, make sure the right number of inputs have been provided   
   num_arguments = command_argument_count()
   
   if ( num_arguments /= 1 ) then  ! to ensuring that you will submit it right
        print *, "ERROR: Invalid usage."
        print *, "Usage: ./fib.x N      N: The Fibonacci number to compute"
        stop 1
   end if

   call get_command_argument(1, argument) !first, read the values 
   
   read(argument,*) n                  !then, convert them to integer
   nthreads = 1
    
    !$omp parallel
       !$omp master
          nthreads = omp_get_num_threads()
       !$omp end master
    !$omp end parallel

    print '("Fibonacci number generator")'
    print *,"     Target number:     ",n
    print *,"     Number of threads: ",nthreads
    
   !$omp parallel shared(n)
      !$omp single
         print *,"fibonacci(%d) = ", n, fibonacci(n)
      !$omp end single
    !$omp end parallel

end program
