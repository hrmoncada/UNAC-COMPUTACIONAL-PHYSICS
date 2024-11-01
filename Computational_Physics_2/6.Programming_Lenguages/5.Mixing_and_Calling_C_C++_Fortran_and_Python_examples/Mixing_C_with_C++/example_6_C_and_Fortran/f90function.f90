module foo_mod
  type foo_type
     real, pointer :: x(:) =>null()
  end type foo_type
end module foo_mod

subroutine foo_new(this, n)
  use foo_mod
  implicit none
  type (foo_type)     :: this
  integer, intent(in) :: n

  allocate(this%x(n))
end subroutine foo_new

subroutine foo_setX(this, vals, n)
  use foo_mod
  implicit none
  type (foo_type)     :: this
  real   , intent(in) :: vals(*)
  integer, intent(in) :: n

  this%x(1:n) = vals(1:n)
end subroutine foo_setX

subroutine foo_getX(this, vals, n)
  use foo_mod
  implicit none
  type (foo_type)     :: this
  real   , intent(out) :: vals(*)
  integer, intent(in) :: n

  vals(1:n) = this%x(1:n)
end subroutine foo_getX

subroutine foo_del(this)
  use foo_mod
  implicit none
  type (foo_type)     :: this

  deallocate(this%x)
end subroutine foo_del
