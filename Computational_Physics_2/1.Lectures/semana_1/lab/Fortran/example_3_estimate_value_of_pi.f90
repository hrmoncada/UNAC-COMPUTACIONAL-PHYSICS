PROGRAM pi
! https://pranabdas.github.io/fortran/monte-carlo-pi/
    IMPLICIT NONE
    doble :: ppi(10), err(10)
    !INTEGER, PARAMETER :: iteration = 1000000
    INTEGER, PARAMETER :: iteration

    REAL :: x, y
    REAL :: x_lo = -1.0
    REAL :: x_hi = 1.0
    REAL :: y_lo = -1.0
    REAL :: y_hi = 1.0

    do i = 1,10
    iteration = 10**i
    INTEGER :: i, monte_area = 0

    DO i = 1, iteration
        CALL random_number(x)
        CALL random_number(y)

        x = x_lo + x * (x_hi - x_lo);
        y = y_lo + y * (y_hi - y_lo);

        IF (x * x + y * y < 1) THEN
            monte_area = monte_area + 1;
        END IF
    END DO

    ppi(i) = 4.0 * monte_area / iteration(i)
    PRINT *, "pi = ",  ppi(i)

    err(i) = abs(1.0 * monte_area / iteration &
            - ATAN(1.0D0)) / ATAN(1.0D0)
    PRINT *, "relative error = ", err(i)
   enddo

END PROGRAM pi
