 subroutine fortfunc(ii,ff)
   integer ii
   real*4  ff
   print *, ii, ff
   print '("ii = ",i2," ff = ",f6.3)', ii, ff
   write(*,'("ii = ",i2," ff = ",f6.3)') ii, ff
   10 format("ii = ",i2," ff = ",f6.3)
   write(*,10) ii, ff


   return
 end

