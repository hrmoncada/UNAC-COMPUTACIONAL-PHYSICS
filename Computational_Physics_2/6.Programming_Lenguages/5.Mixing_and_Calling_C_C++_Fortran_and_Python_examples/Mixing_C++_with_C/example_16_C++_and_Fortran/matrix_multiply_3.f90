!https://github.com/ashwith/workspace/blob/master/fortran/matrixmultiply.f90
!Copyright (C) 2007 Ashwith Jerome Rego
!
!This program is free software: you can redistribute it and/or modify
!it under the terms of the GNU General Public License as published by
!the Free Software Foundation, either version 3 of the License, or
!(at your option) any later version.
!
!This program is distributed in the hope that it will be useful,
!but WITHOUT ANY WARRANTY; without even the implied warranty of
!MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
!GNU General Public License for more details.
!
!You should have received a copy of the GNU General Public License
!along with this program.  If not, see <http://www.gnu.org/licenses/>.


PROGRAM MULMAT
  IMPLICIT NONE
  REAL, ALLOCATABLE, DIMENSION(:,:) :: MatA, MatB, MatC
  INTEGER :: rowsA, colsA, rowsB, colsB, rowsC, colsC
  INTEGER :: i,j, ErrCode
  
  PRINT*,"Enter order of Matrix A (rows,columns):"
  READ*,rowsA,colsA
  ALLOCATE(MatA(rowsA,colsA))
  PRINT*,"Enter elements of Matrix A row wise"
  DO i = 1, rowsA
    READ*,(MatA(i,j),j = 1, colsA)
  END DO
  
  PRINT*,"Enter order of Matrix B (rows,columns):"
  READ*,rowsB,colsB
  ALLOCATE(MatB(rowsB,colsB))
  PRINT*,"Enter elements of Matrix B row wise"
  DO i = 1, rowsB
    READ*,(MatB(i,j),j = 1, colsB)
  END DO
  ALLOCATE(MatC(rowsA,colsB))
  CALL MATRIXPRODUCT(MatA, rowsA, colsA, MatB, rowsB, colsB, MatC, rowsC, colsC, ErrCode)
  IF (ErrCode == 1) THEN
    PRINT*,"A x B = "
    DO i = 1, rowsC
      PRINT *,(MatC(i,j), j = 1, colsC)
    END DO
  ENDIF
END PROGRAM MULMAT
!Subroutine to find product of two matrices
!Author : Louisda16th a.k.a Ashwith J. Rego
!Description:
!Product of two matrices is defined by
!c(i,j) = a(i,1)*b(1,j) + a(i,2)*b(2,j)+........+a(i,n)*b(n,j)
!
SUBROUTINE MATRIXPRODUCT(A, rowsA, colsA, B, rowsB, colsB, C, rowsC, colsC, ErrCode)
!Declarations
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: rowsA, colsA, rowsB, colsB !Matrix Dimensions
  INTEGER, INTENT(INOUT) :: rowsC, colsC, ErrCode !Product matrix dimensions
  REAL, DIMENSION(rowsA,colsA) :: A !Matrix A
  REAL, INTENT(IN), DIMENSION(rowsB,colsB) :: B !Matrix B
  REAL, DIMENSION(rowsA,colsC) :: C !Matrix C
  
  INTEGER :: i, j, k !Counters
  
  IF (colsA /= rowsB) THEN !Two matrices can be multiplied if and only if the number of columns
    PRINT*,"Error! Order of matrices donot match" !of the first matrix equals the number of rows of the second
    ErrCode = -1 !ErrCode = -1 => Subroutine returned unsuccessfully
    RETURN
  ELSE
    rowsC = rowsA
    colsC = colsB
  ENDIF
  
  !Initialize product matrix to 0
  DO i = 1, rowsC
    DO j = 1, ColsC
      C(i,j) = 0
    END DO
  END DO
  
  !Find product as per above formula
  DO i = 1, rowsA
    DO j = 1, colsB
      DO k = 1, colsA
        C(i,j) = C(i,j) + A(i,k)*B(k,j)
      END DO
    END DO
  END DO
  
  !ErrCode = 1 => Subroutine returned successfully
  ErrCode = 1
  
END SUBROUTINE MATRIXPRODUCT
