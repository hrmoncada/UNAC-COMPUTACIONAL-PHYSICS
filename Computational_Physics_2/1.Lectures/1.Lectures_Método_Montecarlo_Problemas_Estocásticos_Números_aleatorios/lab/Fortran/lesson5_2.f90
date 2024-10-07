! https://kamemori.com/fortran/quick_introduction/lesson05.html
program main
  implicit none
  integer :: isample, nsample
  real(8) :: x, f, s

  nsample = 10000

  s = 0d0
  open(30,file="pi_montecarlo.out")
  do isample = 1, nsample
     call random_number(x)
     f = 4d0/(1d0+x**2)
     s = s + f
     write(30,"(I10,2x,e26.16e3)")isample,s/isample
  end do
  close(30)

  
end program main
