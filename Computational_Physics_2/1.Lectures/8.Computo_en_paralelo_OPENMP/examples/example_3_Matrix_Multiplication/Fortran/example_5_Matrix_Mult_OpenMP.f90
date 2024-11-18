! https://cyber.dabamos.de/programming/modernfortran/openmp.html
! benchmark.f90
! $ gfortran10 -O3 -march=native -ffast-math -fopenmp -o benchmark benchmark.f90
!
! The parallised loop, running in 2 threads on an Intel Core i7 (Ivy Bridge), is nearly twice as fast as the non-parallised loop:
! 
! $ ./benchmark
! single:   5.250 s
! OpenMP:   2.755 s  
program benchmark
    use, intrinsic :: omp_lib
    implicit none
    integer, parameter :: dp       = kind(0.0d0)
    integer, parameter :: n        = 2000
    integer, parameter :: nthreads = 4

    integer       :: i, j, k
    real(kind=dp) :: t1, t2
    real(kind=dp) :: a(n, n), b(n, n), c(n, n)

    ! Set number of threads to use.
    call omp_set_num_threads(nthreads)

    ! Initialise the PRNG and fill matrices A and B with random numbers.
    call random_seed()
    call random_number(a)
    call random_number(b)

    c = 0.0_dp
    t1 = omp_get_wtime()

    ! Calculate C = A * B sequentially.
    do j = 1, n
        do k = 1, n
            do i = 1, n
                c(i, j) = c(i, j) + a(i, k) * b(k, j)
            end do
        end do
    end do

    t2 = omp_get_wtime()
    print '(a, f7.3, a)', 'single: ', t2 - t1, ' s'

    c = 0.0_dp
    t1 = omp_get_wtime()

    ! Calculate C = A * B in parallel with OpenMP, using static scheduling.
    !$omp parallel shared(a, b, c) private(i, j, k)
    !$omp do schedule(static)
    do j = 1, n
        do k = 1, n
            do i = 1, n
                c(i, j) = c(i, j) + a(i, k) * b(k, j)
            end do
        end do
    end do
    !$omp end do
    !$omp end parallel

    t2 = omp_get_wtime()
    print '(a, f7.3, a)', 'OpenMP: ', t2 - t1, ' s'
end program benchmark
