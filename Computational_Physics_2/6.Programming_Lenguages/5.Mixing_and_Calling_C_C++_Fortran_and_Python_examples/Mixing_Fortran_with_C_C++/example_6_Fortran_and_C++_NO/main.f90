!  https://www.ibm.com/docs/en/xl-fortran-aix/15.1.2?topic=calls-mixing-fortran
! 
!Example 3: Main Program in FORTRAN, with Subroutines in C, C++, and Fortran
! 
! @Compile the C++ code into object file as:
! $ g++ -c cppfunction.cpp
! 
! @Compile the C code into object file as:
! $ gcc -c cfunction.c
! 
! @Compile the Fortran  code into object file as:
! $ gfortran -c main.f90
! 
! @Link the object files:
! $ gfortran -lt  -o out  main.o f90function.o cppfunction.o cfunction.o

! Main Fortran program that calls C++ (main.f90)

program main
  integer idim, idim1

  idim = 35
  idim1 = 45

  write(6,*) 'Inside Fortran calling first C function'
  call cfun(idim)
       
  write(6,*) 'Inside Fortran calling second C function'
  call cfun1(idim1)
       
  write(6,*) 'Exiting the Fortran program'
       
end
