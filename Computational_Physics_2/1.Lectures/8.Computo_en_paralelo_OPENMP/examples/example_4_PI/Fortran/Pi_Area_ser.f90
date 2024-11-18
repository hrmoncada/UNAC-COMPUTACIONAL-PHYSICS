!**********************************************************************
!   piArea.f90 - compute pi by counting random points in circle and
!                  circumscribing square.
!                The circle has centre in the origin and radius 1
!
!
!   Each process:
!    1) receives the number of rectangles used in the approximation
!    2) generates and count points in rectangle and circle
!    3) Synchronizes for a global summation.
!   Process 0 prints the result.
!
!  Variables:
!
!    pi          the calculated result
!    n           number of random points 
!    x1, x2      extremes of each rectangle
!    SqPoints    points in each rectangle
!    CiPoints    points in circle      
!
!****************************************************************************
program main
 implicit none

 real(8), parameter :: PI25DT=4.0D0*ATAN(1.0D0)
! (PI25DT = 3.141592653589793238462643d0)

 real(8) ::  pi, h
 real(8) ::  sTime=0, eTime=0, elapsed
 real(8) :: x, y, x1, x2, y1, y2
 integer :: n, nt, i, rc, ierr, ls
 integer :: SqPoints, CiPoints
 
 integer :: OMP_GET_NUM_THREADS
 real(8) :: OMP_GET_WTIME

  do
        write(6,"('Enter the number of points: (0 quits)') ")
        read(5,*) n
       	 
       !$ sTime = OMP_GET_WTIME()
    
! check for quit signal
     if ( n .le. 0 ) exit

    x1 = -1.0d0
    x2 = 1.0d0
    y1 = -1.0d0
    y2 = 1.0d0

    SqPoints  = 0
    CiPoints  = 0
    ! Insert parallel region, pay attention to  shared or private variables
    ! and to the operations contained inside the the loop
    do i = 1, n
       call random_number(x); x = x1 + x * (x2 - x1)
       call random_number(y); y = y1 + y * (y2 - y1)
       SqPoints = SqPoints + 1
       if ( SQRT( x*x + y*y ) <= 1.0D0 ) CiPoints = CiPoints + 1
    enddo

        pi = 4.0D0 * ( DBLE(CiPoints) / DBLE(SqPoints) )
        write(6, "(' pi is approximately: ', F18.16, &
        &       '  Error is: ', F18.16)") pi, abs(pi - PI25DT)
       !$ eTime = OMP_GET_WTIME()
        write(6, "(' Wall clock time = ',F6.2/)") (eTime-sTime)
  enddo

 stop
end

