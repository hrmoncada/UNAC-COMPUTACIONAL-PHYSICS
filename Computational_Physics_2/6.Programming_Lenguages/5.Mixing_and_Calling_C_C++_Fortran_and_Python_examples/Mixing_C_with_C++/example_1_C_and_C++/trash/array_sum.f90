subroutine array_sum(a, b, c, n, sumC)
  implicit none 
  integer :: n, sumC, i  ! local variables  
  integer, dimension (n), intent (out) :: a, b, c
  do i = 1, n
     c(i) = a(i) + b(i)
     sumC = sumC + c(i)
   enddo  

   print *, 'sumC =  ',sumC ! sum all elementsin c
   
   arraysize_a = size(a)
   arraysize_b = size(b)
   arraysize_c = size(cc)
    
   print *,'sum array a = ', sum(a), 'array size = ', arraysize_a 
   print *,'sum array b = ', sum(b), 'array size = ', arraysize_b 
   print *,'sum array c = ', sum(c), 'array size = ', arraysize_c
   
   return 
end
