integer function f90function(i) RESULT(sq)
  integer i
  print '("i = ",i2)', i
  sq = i*2
  print '("sq = ",i2)', sq
  return
end
