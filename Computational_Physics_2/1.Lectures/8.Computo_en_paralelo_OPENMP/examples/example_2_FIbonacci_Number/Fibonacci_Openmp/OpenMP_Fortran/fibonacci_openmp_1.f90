!***********************************************************************************
! gfortran -o out -fopenmp fibonacci_openmp_1.f90
! export OMP_NUM_THREADS=8
! ./out 40
!Fibonacci number generator.
!   Target number: 40
!   Number of threads: 1
! The 40th fibonacci number is: 102334155
! Took 0.770840 seconds to compute.
!***********************************************************************************/
module fibonacci_module
  implicit none
  
contains

   function get_time() result(rTime)
     implicit none
     integer :: values(8)
     real    :: rTime
     
! Get the values
     call date_and_time(values=values)
   
! From https://gcc.gnu.org/onlinedocs/gfortran/DATE_005fAND_005fTIME.html
! values(5) ... The hour of the day
! values(6) ... The minutes of the hour
! values(7) ... The seconds of the minute
! values(8) ... The milliseconds of the second 

! Calculate time since midnight
      rTime = ( values(5) )*60.         ! Hours to minutes
      rTime = ( rTime + values(6) )*60. ! Minutes to seconds
      rTime = ( rTime + values(7) )*1e3 ! Seconds to milliseconds
      rTime = rTime + values(8)         ! Add milliseconds
   end function get_time
   
! Calculate the Fibonacci number of the given integer.
! This program calculates the nth fibonacci number
   recursive integer function fibonacci(n) result(res)
     integer, intent(in) :: n   !< If n <= 0 then 0 is assumed.
     !integer             :: res !< Fibonacci number
     integer             :: x, y
     
     if ( n < 2 ) then
       res = n
     else
       !$omp task shared(x) if(n>10)
       x = fibonacci(n - 1)
       !$omp end task
       !$omp task shared(y) if(n>10)
       y = fibonacci(n - 2)
       !$omp end task
       !$omp taskwait
       res = x + y
     end if
   end function fibonacci
end module fibonacci_module

program fibonacci_num
   use omp_lib
   use fibonacci_module
   implicit none
   integer       :: fibN, nthreads, output, num_arguments
   real          :: start_time, end_time
   character(60) :: argument
   
!first, make sure the right number of inputs have been provided   
   num_arguments = command_argument_count()
   
   if ( num_arguments /= 1 ) then  ! to ensuring that you will submit it right
        print *, "ERROR: Invalid usage."
        print *, "Usage: ./fib.x N      N: The Fibonacci number to compute"
        stop 1
   end if
   
  call get_command_argument(1, argument) !first, read the values 
  read(argument,*) fibN                  !then, convert them to integer
  nthreads = 1
  !$omp parallel
     !$omp master 
        nthreads =  omp_get_num_threads()
     !$omp end master
  !$omp end parallel
  
  print '("Fibonacci number generator")'
  print *,"     Target number:     ",fibN
  print *,"     Number of threads: ",nthreads

  start_time = get_time()
  
!$omp parallel
     !$omp master 
         output = fibonacci(fibN)
      !$omp end master
!$omp end parallel
  
  end_time = get_time()

  print '("The ",I5,"th fibonacci number")', fibN
  print *,"The fibonacci number is: ", output
  print '("Took ",f10.1," seconds to compute")', end_time - start_time

end program
