subroutine f90_array_product(a, b, c, n, productC)
!   implicit none 
  integer :: n, i  ! local variables  
  float productC
  float, dimension (n), intent (out) :: a, b, c
   print *, 'product =  ',productC ! product all elementsin c
  do i = 1, n
     c(i) = a(i) * b(i)
     productC = productC *  c(i)
   enddo  

   print *, 'product =  ',productC ! product all elementsin c
   
!    arraysize_a = size(a)
!    arraysize_b = size(b)
!    arraysize_c = size(cc)
!     
!    print *,'product array a = ', product(a), 'array size = ', arraysize_a 
!    print *,'product array b = ', product(b), 'array size = ', arraysize_b 
!    print *,'product array c = ', product(c), 'array size = ', arraysize_c
   return 
end
