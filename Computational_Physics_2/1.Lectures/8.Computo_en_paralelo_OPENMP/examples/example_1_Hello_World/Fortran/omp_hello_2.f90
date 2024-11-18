! https://curc.readthedocs.io/en/latest/programming/OpenMP-Fortran.html
PROGRAM Parallel_Stored_Hello
USE OMP_LIB

INTEGER :: thread_id

!$OMP PARALLEL PRIVATE(thread_id)

    PRINT *, “Hello from process: ”, OMP_GET_THREAD_NUM()

!$OMP END PARALLEL

END  program
