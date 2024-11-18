! https://docs-dev.nersc.gov/cgpu/examples/
! compiled with the GCC Fortran compiler gfortran from the gcc/8.1.1-openacc-gcc-8-branch-20190215 module:
! $ gfortran -fopenmp -foffload=nvptx-none="-Ofast -lm -misa=sm_35" -o main.ex main.f90
! $ srun -n 1 nvprof ./main.ex


program main
  implicit none

  integer, parameter :: sz = 32768
  integer, dimension(sz) :: arr
  integer :: i

  do i = 1, sz
    arr(i) = 42
  end do

  !$omp target teams distribute parallel do map(tofrom: arr(1:sz))
  do i = 1, sz
    arr(i) = arr(i) + 1
  end do

  print *, "After the target region is executed, arr(1) = ", arr(1)

end program main
