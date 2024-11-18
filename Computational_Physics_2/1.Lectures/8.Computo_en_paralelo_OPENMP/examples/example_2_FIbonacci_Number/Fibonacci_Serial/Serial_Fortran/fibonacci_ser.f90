program main
  implicit none
  integer :: n =10
  interface 
     function fib(n)
       integer, intent(in) :: n 
       integer :: fib
     end function fib
  end interface

  print *, fib(n)

end program main

recursive function fib (n)  result (fnum) 
  integer, intent(in)  :: n
  integer :: i,j
  integer :: fnum
  if (n<2) then 
     fnum = n
  else

     i= fib(n-1)

     j= fib(n-2)

     fnum = i+j
  endif
end function fib