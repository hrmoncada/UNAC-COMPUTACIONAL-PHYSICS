PROGRAM MatrMult 
   IMPLICIT NONE

   REAL(8), DIMENSION(:,:), ALLOCATABLE :: A, B, C, tC
   INTEGER :: L, M, N, N0, N1
   REAL ::   cput2, cput1

   INTEGER :: i, j, k, t, st
   REAL(8) :: rmin, rmax
   
!  OMP variables
   INTEGER :: OMP_GET_THREAD_NUM, OMP_GET_NUM_THREADS
   REAL(8) :: OMP_GET_WTIME, wall1, wall2
   INTEGER :: my_rank, numprocs
!
   ! Input Data
   WRITE(*,"(A)") " Input dimensions of matrices  L, M, N "
   READ*,L, M, N
   WRITE(*,"(A,3(1x,I6))") " Matrices dimensions are: ",L,M,N

   !  Master allocates entire matrices
   ALLOCATE(A(L,M), B(M,N), C(L,N), STAT=st)
   IF ( st /= 0 ) THEN
   	  WRITE(*,*) "Error allocating matrices "
   	  STOP
   END IF


   numprocs=1
   my_rank=0
   
   A = 0.0; B = 0.0; C = 0.0

   ! Every process executes
   !  Initializations
   
   ! Do it in parallel 
   DO i = 1, L
      DO k = 1, M
         A(i,k) = REAL(i-k) / REAL(i+k)
      END DO
   END DO

   ! Do it in parallel 
   DO j = 1, N
      DO k = 1, M
         B(k,j) = 0.01 * REAL(k-j) / REAL(k+j)
      END DO
   END DO

   !This statement is executed only by master thread if compiler openmp flag is used
   !$ wall1 = OMP_GET_WTIME()
   CALL CPU_TIME(cput1)
   
   ! Insert parallel region, pay attention to  shared or private variables

   !This statement is executed only by master thread if compiler openmp flag is used
   ! numprocs = OMP_GET_NUM_THREADS()
   ! my_rank = OMP_GET_THREAD_NUM()
   
   
   
   CALL intervals(N,N0,N1,numprocs,my_rank)
   !  Compute multiplication
   !This statement is executed by all threads but only one at a time
      print*," Process ",my_rank," of ",numprocs," computes C(:,",N0,",",N1,")"
   
   	   
   DO j = N0, N1
      DO i = 1, L
         C(i,j) = 0.0
         DO k = 1, M
            C(i,j) = C(i,j) + A(i,k) * B(k,j)
         END DO
      END DO
   END DO
   ! Close parallel region

   CALL CPU_TIME(cput2)
!   This statement is executed only by master thread if compiler openmp flag is used
   !wall2 = OMP_GET_WTIME()

   ! Check for correctness
   ALLOCATE(tC(L,N), STAT=st)
   IF ( st /= 0 ) THEN
      	 WRITE(*,*) "Error allocating matrix tC !!!"
      	 STOP
   END IF
      
      	   	   
      tC = MATMUL(A,B)

      rmin = MINVAL(tc-C); rmax = MAXVAL(tC-C)

      WRITE(*,*) " rmin, rmax = ",rmin,rmax
    
      WRITE(*,*) "Cpu and elapsed time are: ",(cput2-cput1),(wall2-wall1)
!
   STOP
END PROGRAM MatrMult  

   SUBROUTINE intervals(length,first,last,segments,n)
      IMPLICIT NONE
      INTEGER, INTENT(IN) :: length,segments,n
      INTEGER, INTENT(OUT) :: first,last

      INTEGER :: delta

      delta = ( length + (segments - 1) ) / segments
      first = delta * n + 1; last = delta * ( n + 1)
      IF ( last > length ) last = length
   
      RETURN
   END SUBROUTINE intervals

