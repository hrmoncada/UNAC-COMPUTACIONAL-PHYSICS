! C functions declaration
interface
    function create_foo_c(a, b) bind(C, name="create_foo")
        use iso_c_binding
        implicit none
        type(c_ptr) :: create_foo_c
        integer(c_int), value :: a
        integer(c_int), value :: b
    end function

    subroutine delete_foo_c(foo) bind(C, name="delete_foo")
        use iso_c_binding
        implicit none
        type(c_ptr), value :: foo
    end subroutine

    function foo_bar_c(foo, c) bind(C, name="foo_bar")
        use iso_c_binding
        implicit none
        integer(c_int) :: foo_bar_c
        ! The const qualification is translated into an intent(in)
        type(c_ptr), intent(in), value :: foo
        integer(c_int), value :: c
    end function

    function foo_baz_c(foo, c) bind(C, name="foo_baz")
        use iso_c_binding
        implicit none
        real(c_double) :: foo_baz_c
        type(c_ptr), intent(in), value :: foo
        real(c_double), value :: c
    end function

    ! void functions maps to subroutines
    subroutine foo_speaker_c(str) bind(C, name="foo_speaker")
        use iso_c_binding
        implicit none
        character(len=1, kind=C_CHAR), intent(in) :: str(*)
    end subroutine
end interface
