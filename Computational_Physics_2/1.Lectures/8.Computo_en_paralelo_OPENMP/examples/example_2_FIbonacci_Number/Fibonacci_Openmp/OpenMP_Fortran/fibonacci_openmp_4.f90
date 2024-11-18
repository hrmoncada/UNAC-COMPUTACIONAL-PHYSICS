!https://books.google.com/books?id=qIERUAp-vVAC&pg=PA132&lpg=PA132&dq=fortran+90+,+f,+openmp,+fibonaccionacci&source=bl&ots=W3YSdzXAWA&sig=ACfU3U1fZFYeXO7XyocBcHRlIf51rrsT5A&hl=en&sa=X&ved=2ahUKEwiZq_jS1bTrAhUQXc
!page 132
! gcc -fopenmp -o out fibonacci_openmp_4.c 
! ./out 40
!Fibonacci number generator.
!   Target number: 40
!   Number of threads: 8
!fibonacci(40) = 102334155

!omp css task input(a) output(out)

recursive integer function fibonacci(a) result(out)

  integer, intent(in) :: a
  integer tmp1, tmp2
  
  if (a <= 1) then
    out = 1
  else 
    tmp1 = fibonacci(a-1)
    
    tmp2 = fibonacci(a-2)
    
    out =  tmp1 + tmp2
   end if
end function

program fibonacci_num
   use omp_lib
   implicit none
   integer :: fibonacci       ! call the function
   character(60) :: argument
   integer :: res , var, nthreads, num_arguments
   
   !first, make sure the right number of inputs have been provided   
   num_arguments = command_argument_count()
   
    if ( num_arguments /= 1 )  then ! to ensuring that you will submit it right
        print *,"ERROR: Invalid usage"
        print *,"Usage: ./fib.x  N    N: The Fibonacci number to compute."
        stop 1
    end if

    call get_command_argument(1, argument) !first, read the values 
   
    read(argument,*) var                  !then, convert them to integer
    nthreads = 1
    
    !$omp parallel
       !$omp master
          nthreads = omp_get_num_threads();
        !$omp end master
    !$omp end parallel
    
    print '("Fibonacci number generator")'
    print *,"     Target number:     ",var
    print *,"     Number of threads: ",nthreads
    
   !omp css start
       res = fibonacci(var-1)
   !omp css finish

   print '("fibonacci(",I2,") = ",I10," ")', var, res
end program
