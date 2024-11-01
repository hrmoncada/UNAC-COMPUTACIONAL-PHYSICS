!https://notmatthancock.github.io/2017/02/10/calling-fortran-from-python.html
!

subroutine threshold_image(image, n, threshold, output)
    ! Inputs: image, n, threshold.
    ! Output: output
    !   output(i,j) is 1 if image(i,j) > threshold and 0 otherwise.

    integer n
    real(8) threshold
    real(8), dimension(n,n) :: image, output

    !f2py intent(in) :: image, threshold
    !f2py intent(hide), depend(image) :: n = shape(image, 0)
    !f2py intent(out) output

    write(*,*) "Hello from the Fortran subroutine!"

    ! Loop through columns and rows and threshold the image.
    do j=1,n
        do i=1,n
            if (image(i,j) > threshold) then
                output(i,j) = 1.0
            else
                output(i,j) = 0.0
            end if
        end do
    end do
end subroutine
