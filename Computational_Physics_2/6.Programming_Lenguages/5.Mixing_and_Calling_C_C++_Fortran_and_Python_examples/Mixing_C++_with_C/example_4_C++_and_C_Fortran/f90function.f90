subroutine f90function(a, b)
! implicit none
  a = 3.0
  b = 4.0
  !print 'f90function (a, b) = (f3.2, %f3.2)\n', a, b
  print "(f12.3)", a
  print "(f12.3)", b
end
