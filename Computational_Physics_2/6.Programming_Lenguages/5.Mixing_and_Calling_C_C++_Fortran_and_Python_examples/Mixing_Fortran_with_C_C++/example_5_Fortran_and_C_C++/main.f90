!  https://www.cae.tntech.edu/help/programming/mixed_languages
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
! $ gfortran -c f90function.f90
! 
! @Link the object files:
! $ gfortran -lt  -o out  main.o f90function.o cppfunction.o cfunction.o


program main
   real a,b
   a = 1.0
   b = 2.0

   print*,'Before Fortran function is called:'
   print*,'a =',a
   print*,'b =',b
   call ffunction(a,b)
   print*,'After Fortran function is called:'
   print*,'a =',a
   print*,'b =',b

   print*,'Before C function is called:'
   print*,'a =',a
   print*,'b =',b
   call cfunction(a,b)
   print*,'After C function is called:'
   print*,'a =',a
   print*,'b =',b

   print*,'Before C++ function is called:'
   print*,'a =',a
   print*,'b =',b
   call cppfunction(a,b)
   print*,'After C++ function is called:'
   print*,'a =',a
   print*,'b =',b

   stop
end
