!https://solarianprogrammer.com/2012/05/11/mixed-language-programming-cpp-11-fortran-2008/
! We are going to implement a Fortran subroutine, callable from C,
! that multiplies two matrices filled with doubles.
! For matrix multiplication we are going to use a Fortran intrinsic function named matmul:

subroutine matrix_multiply(A, rows_A, cols_A, B, rows_B, cols_B, C, rows_C, cols_C) bind(c)
  use iso_c_binding
  integer(c_int) :: rows_A, cols_A, rows_B, cols_B, rows_C, cols_C
  real(c_double) :: A(rows_A, cols_A), B(rows_B, cols_B), C(rows_C, cols_C)

  C = matmul(A, B)

end subroutine matrix_multiply
