! https://www.mkdynamics.net/current_projects/Fortran/Introduction_to_Programming_Using_Fortran/Section_14_Pi_Estimation.html
program piestimation

! declare variabes

implicit none

integer                             :: count, alstat, i, incount
real                                :: x, y, pi_est, pt
real, allocatable, dimension (:,:)  :: points

! display inital header
    write (*, '(/a/)') "Program Example - Pi estimation"

! prompt for and obtain count value
    ! This section will be skipped for the Jupyter Notebook
    !do
        ! prompt for count value
        ! write (*, '(a)', advance="no") "Enter Count (100 - 1,000,000): "

        ! read count value
        ! read (*,*) count

        ! if count is correct, exit loop
        !if ( count >= 100 .and. count <= 1000000 ) exit

        ! Otherwise, display error message
        !write (*, '(a,a,/a)') "Error, count must be ", &
        !    "between 100 and 1,000,000.",              &
        !    "Please re-enter."

    !end do

! Set number of estimation points (i.e. count) = 1 million
count = 1000000

! allocate two dimensional array
    allocate (points(count,2), stat=alstat)

    ! Check for allocation errors
    if ( alstat /= 0 ) then
        write (*, '(a,a/a)') "Error, unable to",        &
            " allocate memory.", "Program terminated."
        stop
    end if


! generate points
    call random_seed()

    ! loop count times
    do i = 1, count

        ! generate x and y values
        call random_number(x)
        call random_number(y)

        ! place (x,y) values in array
        points(i,1) = x
        
        points(i,2) = y
    end do

! perform monte carlo estimation

    ! set count of samples inside circle = 0
    incount = 0

    ! loop count times
    do i = 1, count

    ! if [ sqrt (x(i)^2 + y(i)^2) < 1.0 ]
    ! increment count of samples inside circle

        pt = points(i,1)**2 + points(i,2)**2
        if (sqrt(pt) < 1.0) incount = incount + 1

    end do

    pi_est = 4.0 * real (incount) / real (count)

! display results
    write (*, '(a, i10)') "The number of points to process is -> ", count
    print *
    write (*, '(a, i10)') "The number of points inside the circle were -> ", incount
    print *
    write (*, '(a, f16.8)') "Estimated Pi Value: ", pi_est
    print *
end program piestimation

            
