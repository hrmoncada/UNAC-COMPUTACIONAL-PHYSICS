!  Fortran 90

PROGRAM hello
    use omp_lib          ! Fortran 90; omp_get_thread_num, omp_get_num_threads

    ! Serial Region  (master thread)
    ! Parameters of the Application
    CHARACTER(30) name   ! Fortran 90

    ! OpenMP Parameters
    INTEGER id, nthreads

    ! Master thread obtains information about itself and its environment.
    nthreads = omp_get_num_threads()       ! get number of threads
    id = omp_get_thread_num()              ! get thread
    CALL getenv("HOST",name)               ! get run-host name
    WRITE (*,*) 'SERIAL REGION:   Runhost:', name, '   Thread:', id, ' of ', nthreads, ' thread    hello, world'

    ! Open parallel region.
    ! Each thread obtains information about itself and its environment.
    !$OMP PARALLEL PRIVATE(name,id,nthreads)
        nthreads = omp_get_num_threads()   ! get number of threads
        id = omp_get_thread_num()          ! get thread
        CALL getenv("HOST",name)           ! get run-host name
        WRITE (*,*) 'PARALLEL REGION:   Runhost:', name, '   Thread:', id, ' of ', nthreads, ' threads   hello, world'
    !$OMP END PARALLEL
    ! Close parallel region.

    ! Serial Region  (master thread)
    WRITE (*,*) 'SERIAL REGION:   Runhost:', name, '   Thread:', id, ' of ', nthreads, ' thread    hello, world'
END PROGRAM hello        ! Fortran 90