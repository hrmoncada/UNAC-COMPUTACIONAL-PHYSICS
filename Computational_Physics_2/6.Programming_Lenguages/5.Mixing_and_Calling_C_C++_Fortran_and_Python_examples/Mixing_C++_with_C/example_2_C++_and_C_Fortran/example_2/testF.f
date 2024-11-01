! http://mordenchina.blogspot.com/2007/06/tutorial-using-cc-and-fortran-together.html
! Compile:
! 
! * f77 -c testF.f
! * g++ -c testC.cpp
! * g++ -o test testF.o testC.o -lg2c
! 
! Run: ./test
! 
! ii= 5 ff= 5.500

subroutine fortfunc(ii,ff)
integer ii
real*4 ff

write(6,100) ii, ff
100 format('ii=',i2,' ff=',f6.3)

return
end