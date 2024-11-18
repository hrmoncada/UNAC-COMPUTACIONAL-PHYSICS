! https://curc.readthedocs.io/en/latest/programming/OpenMP-Fortran.html
PROGRAM Parallel_Ordered_Hello
USE OMP_LIB

INTEGER :: thread_id

!$OMP PARALLEL PRIVATE(thread_id)

    thread_id = OMP_GET_THREAD_NUM()
    DO i = 0, OMP_GET_MAX_THREADS()
        PRINT *, "Hello from process: ", thread_id
    END DO

!$OMP END PARALLEL

END program
