! https://abhila.sh/writing/1.0/cfmix.html
! gcc -c gauss_legendre_10pts.c
! gfortran -c main_integrate.f90
! gfortran -o out main_integrate.o gauss_legendre_10pts.o

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!
!!BY ABHILASH REDDY M. 2016
!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
program integrate
  use, intrinsic :: iso_c_binding,cl=>c_long_double
  implicit none

  interface
    function gl10(a, b, f) &
    bind(c,name='Gauss_Legendre_Integration_10pts') !the function name case-sensitive because C is case-sensitive
      import::cl,c_funptr
      real(cl), intent(in), value :: a, b
      type(c_funptr), intent(in), value :: f
      real(cl) gl10
    endfunction

    function f1(x) bind(c)
      import::cl
      real(cl),intent(in), value ::x
      real(cl) f1
    endfunction
  endinterface

  type(c_funptr) :: f1_cptr
  real(cl)  :: a,b

  a=0; b=1

  f1_cptr = c_funloc (f1) !gets the C address of the fortran function f1
  write(*,*)'error= ',gl10(a,b,f1_cptr)-4*atan(1.0_cl)
endprogram

function f1(x) bind(c)
  use, intrinsic :: iso_c_binding,cl=>c_long_double
  implicit none
  real(cl),intent(in), value ::x
  real(cl) f1
  f1=4.0/(1.0+x**2)
endfunction
