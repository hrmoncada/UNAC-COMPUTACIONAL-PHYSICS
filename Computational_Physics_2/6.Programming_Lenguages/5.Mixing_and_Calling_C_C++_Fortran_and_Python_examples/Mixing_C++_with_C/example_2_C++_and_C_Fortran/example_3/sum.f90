!https://wiki.calculquebec.ca/w/C%2B%2B_:_appels_Fortran/en 
![name@server $] gfortran sum.f90 -c -o sum.o
!  [name@server $] g++ sum.o call_fortran.cpp -o a.out
!  [name@server $] ./a.out
 
real*8 function fonction_sum(fsize,fvec)
 
    integer fsize,i
    real*8 fvec(fsize)
    real*8 sum
 
    function_sum=0.0
 
    do i=1,fsize
      fonction_sum=fonction_sum+fvec(i)  
    end do
 
    return
 
end 
 
subroutine subroutine_sum(fsize,fvec,sum)
 
    integer fsize,i
    real*8 fvec(fsize)
    real*8 sum
 
    sum=0.0
 
    do i=1,fsize
      sum=sum+fvec(i)
    end do
 
end