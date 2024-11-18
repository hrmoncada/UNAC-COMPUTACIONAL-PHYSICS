! https://cyber.dabamos.de/programming/modernfortran/date-and-time.html
! The following example implements a simple Monte Carlo simulation that estimates the number Pi, and measures the time the computer needs for this task.
! pi.f90
!$ gfortran -fopenmp -o pi pi.f90
!$ export OMP_NUM_THREADS=8
!$ ./pi
!t:  1.229 s
!Pi: 3.14110994
program main
    use, intrinsic :: omp_lib
    implicit none
    integer(kind=8), parameter :: N = 10**7
    real(kind=8)               :: t1, t2
    real(kind=8)               :: pi

    call random_seed()

    t1 = omp_get_wtime()
    pi = monte_carlo_pi(N)
    t2 = omp_get_wtime()

    print '("t:  ", f0.3, " s")', t2 - t1
    print '("Pi: ", f0.8)', pi
contains
    function monte_carlo_pi(n) result(pi)
        integer(kind=8), intent(in) :: n
        real(kind=8)                :: pi
        real(kind=8)                :: x, y
        integer(kind=8)             :: c, i

        c = 0

        do i = 1, n
            call random_number(x)
            call random_number(y)

            if (x**2 + y**2 < 1) &
                c = c + 1
        end do

        pi = (dble(c) / n) * 4
    end function monte_carlo_pi
end program main
