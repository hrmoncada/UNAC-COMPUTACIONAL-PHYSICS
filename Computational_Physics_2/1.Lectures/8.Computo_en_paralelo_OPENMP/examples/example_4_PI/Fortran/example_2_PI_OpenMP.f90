!https://www.hpc.cineca.it/content/pi-fortran-openmp
!---------------------------------------------c
!  Exercise: Pi                               c
!                                             c
!  Compute the value of PI using the integral c
!  pi = 4* int 1/(1+x*x)    x in [0-1]        c
!                                             c
!  The integral is approximated by a sum of   c
!  n interval.                                c
!                                             c
!  The approximation to the integral in each  c
!  interval is: (1/n)*4/(1+x*x).              c
!---------------------------------------------c
program pigreco
#ifdef _OPENMP
    use omp_lib
#endif
    implicit none

    integer(selected_int_kind(18)) :: i
    integer(selected_int_kind(18)), parameter :: intervals=1e7
    integer:: nthreads, threadid

    real(kind(1.d0)) :: dx,sum,x
    real(kind(1.d0)) :: f,pi
    real(kind(1.d0)), parameter :: PI25DT = acos(-1.d0)
#ifdef _OPENMP
    real(kind(1.d0)) :: time1, time2
#else 
    real :: time1, time2
#endif
!$omp parallel 
#ifdef _OPENMP
    nthreads = OMP_GET_NUM_THREADS()
    threadid = OMP_GET_THREAD_NUM()
    if(threadid.eq.0) then
       write(*,*) "Open-MP version with threads = ", nthreads
    endif
#else 
    write(*,*) "Serial version "
#endif
!$omp end parallel

    print *, 'Number of intervals: ', intervals
    sum=0.d0
    dx=1.d0/intervals

#ifdef _OPENMP
    time1 = omp_get_wtime()
#else 
    call cpu_time(time1)
#endif

!$omp parallel do private(x,f) &
!$omp reduction(+:sum)
    do i=intervals, 1, -1
        x=dx*(i-0.5d0)
        f=4.d0/(1.d0+x*x)
        sum=sum+f
    end do
!$omp end parallel do
    pi=dx*sum
#ifdef _OPENMP
    time2 = omp_get_wtime()
#else
    call cpu_time(time2)
#endif

    PRINT '(a13,2x,f30.25)',' Computed PI =', pi
    PRINT '(a13,2x,f30.25)',' The True PI =', PI25DT
    PRINT '(a13,2x,f30.25)',' Error        ', PI25DT-pi
    PRINT *, ' '
    PRINT *, 'Elapsed time ', time2-time1 ,' s'

end program



© Copyright 2012 SCAI - SuperComputing Applications and Innovation - CINECA (P.IVA: 00502591209  -  Privacy e Cookies policy)  

