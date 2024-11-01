program test
    use libfoo
    implicit none
    type(foo) :: f

    ! Create an object of type foo
    f = foo(3, 4)

    ! Call bound procedures (member functions)
    write(*,*) f%bar(60), " should be ", 63
    write(*,*) f%baz(10d0), " should be ", 14.0d0

    call foo_speaker("From Fortran!")

    ! The destructor should be called automatically here, but this is not yet
    ! implemented in gfortran. So let's do it manually.
#ifdef __GNUC__
    call f%delete
#endif
end program
