! Multiply matrices A and B using the intrinsic Fortran function matmul, the result is stored in matrix C
subroutine matrix_multiply(A, rows_A, cols_A, B, rows_B, cols_B, C, rows_C, cols_C) bind(c)
    use iso_c_binding
    integer(c_int) :: rows_A, cols_A, rows_B, cols_B, rows_C, cols_C
    real(c_double) :: A(rows_A, cols_A), B(rows_B, cols_B), C(rows_C, cols_C)

    C = matmul(A, B)
end subroutine matrix_multiply
