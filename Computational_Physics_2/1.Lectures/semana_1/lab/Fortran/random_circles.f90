program estimate_pi
! https://stackoverflow.com/questions/59520304/estimation-of-pi-using-monte-carlo-method-in-fortran
! http://homepages.math.uic.edu/~hanson/pi_mpi.c
! https://pranabdas.github.io/fortran/monte-carlo-pi/
    implicit none
    real :: length, r, rand_x, rand_y, radius, area_square, square_points, circle_points, origin_dist, approx_pi
    integer :: i, iterations

    ! length of side of a square
    length = 1
    ! radius of the circle
    radius = length/2

    ! area of the square considered
    area_square = length * length

    square_points = 0
    circle_points = 0

    ! number of iterations
    iterations = 10000000

    i = 0
    do while (i < iterations)
        ! generate random x and y values
        call random_number(r)
        rand_x = - length/2 + length * r
        call random_number(r)
        rand_y = - length/2 + length * r

        ! calculate the distance of the point from the origin
        origin_dist = rand_x * rand_x + rand_y * rand_y

        ! check whether the point is within the circle
        if (origin_dist <= radius * radius) then
            circle_points = circle_points +  1
        end if

        ! total number of points generated
        square_points = square_points + 1

        ! approximate value of pi
        approx_pi = 4 * (circle_points/square_points)

        ! increase the counter by +1
        i = i + 1
    end do

    print*, 'Approximate value of pi is', approx_pi
    print*, 'Number of points in circle', circle_points    
    print*, 'Number of points in square', square_points
end program estimate_pi