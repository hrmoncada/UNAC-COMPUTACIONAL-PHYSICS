! https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
! $ mpif90 example_3_Send_Recv_or_point_a_point.f90 -o out
! $ mpirun -np 4 ./out
! Enter integer number:
! 100
! Slave  1 has received n=100 from  0
!         100           0         101           1
! Slave  2 has received n=100 from  0
!         100           0         101           1
! Slave  3 has received n=100 from  0
!         100           0         101           1
! Master 0 received from slave  1: n=100
!         100           1         201           1
! Master 0 received from slave  2: n=200
!         200           2         201           1
! Master 0 received from slave  3: n=300
!         300           3         201           1

PROGRAM point_a_point
   USE mpi
   IMPLICIT NONE
   INTEGER, DIMENSION(MPI_STATUS_SIZE) :: statut
   INTEGER, PARAMETER :: tagm=101, tagr=201, master=0
   INTEGER :: rang,nprocs,i,n,ierr


   CALL MPI_INIT(ierr)
   CALL MPI_COMM_RANK(MPI_COMM_WORLD,rang,ierr)
   CALL MPI_COMM_SIZE(MPI_COMM_WORLD,nprocs,ierr)

   IF (rang == master) THEN
     WRITE(*,*) 'Enter integer number:'
     READ(*,*) n

     DO i=1,nprocs-1
        CALL MPI_SEND(n,1,MPI_INTEGER,i,tagm,MPI_COMM_WORLD,ierr)
     END DO

     DO i=1,nprocs-1
        CALL MPI_RECV(n,1,MPI_INTEGER,i,tagr,MPI_COMM_WORLD,statut,ierr)
        WRITE(*,'(A,I2,A,I2,A,I3)') "Master",rang," received from slave ",i,": n=",n
        WRITE(*,*) n,statut(MPI_SOURCE),statut(MPI_TAG),statut(MPI_ERROR)
     END DO
   ELSE
     CALL MPI_RECV(n,1,MPI_INTEGER,master,tagm,MPI_COMM_WORLD,statut,ierr)
     WRITE(*,'(A,I2,A,I3,A,I2)') "Slave ",rang," has received n=",n," from ",master
     WRITE(*,*) n,statut(MPI_SOURCE),statut(MPI_TAG),statut(MPI_ERROR)

     n = n*rang
     
     CALL MPI_SEND(n,1,MPI_INTEGER,master,tagr,MPI_COMM_WORLD,ierr)
   END IF

   CALL MPI_FINALIZE(ierr)

END PROGRAM point_a_point
