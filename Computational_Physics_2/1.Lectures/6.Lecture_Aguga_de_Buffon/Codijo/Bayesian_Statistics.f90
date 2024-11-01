!  Console1.f90 
! Bayesian Statistics - standard example and Fortran
!  FUNCTIONS:
!  Console1 - Entry point of console application.
! https://community.intel.com/t5/Intel-Fortran-Compiler/Bayesian-Statistics-standard-example-and-Fortran/td-p/1167797/page/2?profile.language=zh-TW

!****************************************************************************
!
!  PROGRAM: Console1
!
!  PURPOSE:  Entry point for the console application.
!
!****************************************************************************

     program mc
        integer :: n,i
        real(8) :: pi, pi1, pi2, averpi
        n=10000
        pi1 = 0.d0
        averpi = 0.d0
        do i=1,60
            print*,i,n
            pi2 = pi(n)
            averpi = (averpi + pi2)/2.d0
          print*,i,n,pi2,(pi2-pi1),averpi
          pi1=pi2
          if(i >= 4)then
              n=n + 1000000
          else
          n = n * 10
          endif
        end do
        end program
 
        function  pi(n)
        integer :: n
        real(8) :: x(2,n),pi
        call random_number(x)
        pi = 4.d0 * dble( count( hypot(x(1,:),x(2,:)) <= 1.d0 ) ) / n
        end function
