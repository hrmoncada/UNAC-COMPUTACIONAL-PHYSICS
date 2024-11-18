!**********************************************************************
!   pi3f90.f - compute pi by integrating f(x) = 4/(1 + x**2)
!
!   Each node:
!    1) receives the number of rectangles used in the approximation.
!    2) calculates the areas of it's rectangles.
!    3) Synchronizes for a global summation.
!   Node 0 prints the result.
!
!  Variables:
!
!    pi  the calculated result
!    n   number of points of integration.
!    x           midpoint of each rectangle's interval
!    f           function to integrate
!    sum,pi      area of rectangles
!    tmp         temporary scratch space for global summation
!    i           do loop index
!****************************************************************************
program main

 real(8), parameter :: PI25DT=4.0D0*ATAN(1.0D0)
! (PI25DT = 3.141592653589793238462643d0)

 real(8) ::  pi, h, sum, x, f, a
 real(8) ::  sTime, eTime, elapsed
 integer :: n, i, rc
 
 real(8) :: OMP_GET_WTIME
 
! function to integrate
 f(a) = 4.d0 / (1.d0 + a*a)

 do
       write(6,"('Enter the number of intervals: (0 quits)') ")
       read(5,"(i10)") n
!$       sTime = OMP_GET_WTIME()

! check for quit signal
    if ( n .le. 0 ) exit

! calculate the interval size
    h = 1.0d0/n

    sum  = 0.0d0
    !cc 
    ! Insert parallel region, pay attention to  shared or private variables
    ! and to the operations contained inside the the loop
    do i = 1, n
       x = h * (dble(i) - 0.5d0)
       sum = sum + f(x)
    enddo
    
    pi = h * sum

    write(6, "(' pi is approximately: ', F18.16, &
        &       '  Error is: ', F18.16)") pi, abs(pi - PI25DT)
    
!$    eTime = OMP_GET_WTIME()
    write(6, "(' Wall clock time = ',F6.2/)") (eTime-sTime)

 enddo

 stop
end

