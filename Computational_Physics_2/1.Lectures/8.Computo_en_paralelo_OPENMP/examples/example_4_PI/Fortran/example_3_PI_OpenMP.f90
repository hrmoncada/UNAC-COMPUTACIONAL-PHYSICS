! https://www.dartmouth.edu/~rc/classes/soft_dev/openmp_examples.html
program pigreco
#ifdef _OPENMP
    use omp_lib
#endif
    implicit none

c$omp parallel default(none)
c$omp&private(i,j,x,y,z,count,niter) shared(pi)
c$omp do
       do j= 1,1000
          niter = niter+100
          count =0
          do i=1,niter
             x=rand()
             y=rand()
             z= x*x +y*y
             if (z .le. 1) count =count+1
          end do
          pi(j)= count/niter*4.
          write(*,10) niter,pi(j)
10        format('Number of trials is: 'i5,'  estimate of pi is:',f8.5)
       end do
c$omp end do
c$omp end parallel
       end
