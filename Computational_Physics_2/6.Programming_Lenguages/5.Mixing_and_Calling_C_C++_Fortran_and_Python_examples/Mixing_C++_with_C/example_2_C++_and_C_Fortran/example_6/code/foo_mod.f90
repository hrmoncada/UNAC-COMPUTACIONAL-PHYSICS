module libfoo
    use iso_c_binding

    private
    public :: foo, foo_speaker

    ! Yes, include is a keyword in Fortran !
    include "foo_cdef.f90"

    ! We'll use a Fortan type to represent a C++ class here, in an opaque maner
    type foo
        private
        type(c_ptr) :: ptr ! pointer to the Foo class
    contains
        ! We can bind some functions to this type, allowing for a cleaner syntax.
#ifdef __GNUC__
        procedure :: delete => delete_foo_polymorph ! Destructor for gfortran
#else
        final :: delete_foo ! Destructor
#endif
        ! Function member
        procedure :: bar => foo_bar
        procedure :: baz => foo_baz
    end type

    ! This function will act as the constructor for foo type
    interface foo
        procedure create_foo
    end interface

contains ! Implementation of the functions. We just wrap the C function here.
    function create_foo(a, b)
        implicit none
        type(foo) :: create_foo
        integer, intent(in) :: a, b
        create_foo%ptr = create_foo_c(a, b)
    end function

    subroutine delete_foo(this)
        implicit none
        type(foo) :: this
        call delete_foo_c(this%ptr)
    end subroutine

    ! Bounds procedure needs to take a polymorphic (class) argument
    subroutine delete_foo_polymorph(this)
        implicit none
        class(foo) :: this
        call delete_foo_c(this%ptr)
    end subroutine

    integer function foo_bar(this, c)
        implicit none
        class(foo), intent(in) :: this
        integer, intent(in) :: c
        foo_bar = foo_bar_c(this%ptr, c)
    end function

    double precision function foo_baz(this, c)
        implicit none
        class(foo), intent(in) :: this
        double precision, intent(in) :: c
        foo_baz = foo_baz_c(this%ptr, c)
    end function

    subroutine foo_speaker(str)
        implicit none
        character(len=*), intent(in) :: str
        character(len=1, kind=C_CHAR) :: c_str(len_trim(str) + 1)
        integer :: N, i

        ! Converting Fortran string to C string
        N = len_trim(str)
        do i = 1, N
            c_str(i) = str(i:i)
        end do
        c_str(N + 1) = C_NULL_CHAR

        call foo_speaker_c(c_str)
    end subroutine
end module
