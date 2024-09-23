! https://kamemori.com/fortran/quick_introduction/lesson05.html
program main
  implicit none
  integer :: isample, nsample, ncount
  real(8) :: x1,x2,r

  nsample = 10000

  open(30,file="montecarlo.out")
  ncount = 0
  do isample = 1, nsample
     call random_number(x1)
     call random_number(x2)

     r = sqrt(x1**2+x2**2)
     if(r < 1d0)ncount = ncount + 1
     write(30,"(I10,2x,I10,2x,e26.16e3)")isample,ncount,4d0*ncount/dble(isample)
     
  end do
  close(30)

end program main
