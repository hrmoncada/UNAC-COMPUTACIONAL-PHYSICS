C  Fortran 77

      PROGRAM HELLO

C     Serial Region  (master thread)
C     Parameters of the Application
      CHARACTER*30 NAME

C     OpenMP Parameters
      INTEGER ID, NTHREADS
      INTEGER OMP_GET_THREAD_NUM, OMP_GET_NUM_THREADS

C     Master thread obtains information about itself and its environment.
      NTHREADS = OMP_GET_NUM_THREADS()
      ID = OMP_GET_THREAD_NUM()
      CALL GETENV("HOST",NAME)
      PRINT *, 'SERIAL REGION:     Runhost:', NAME, '   Thread:', ID,
     &    ' of ', NTHREADS, ' thread    hello, world'

C     Open parallel region.
C     Each thread obtains information about itself and its environment.
C$OMP PARALLEL PRIVATE(NAME,ID,NTHREADS) 
      NTHREADS = OMP_GET_NUM_THREADS()
      ID = OMP_GET_THREAD_NUM()
      CALL GETENV("HOST",NAME)
      PRINT *, 'PARALLEL REGION:   Runhost:', NAME, '   Thread:', ID,
     &    ' of ', NTHREADS, ' threads   hello, world'
C$OMP END PARALLEL 
C     Close parallel region.

C     Serial Region  (master thread)
      PRINT *, 'SERIAL REGION:     Runhost:', NAME, '   Thread:', ID,
     &    ' of ', NTHREADS, ' thread    hello, world'
      END