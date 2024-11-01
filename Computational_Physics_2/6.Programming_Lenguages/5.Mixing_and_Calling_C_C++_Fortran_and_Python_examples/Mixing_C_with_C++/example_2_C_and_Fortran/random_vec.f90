subroutine ranvec(v, n)
   integer                        :: n
   double precision, dimension(n) :: v

   call random_seed()
   call random_number(v)

end
