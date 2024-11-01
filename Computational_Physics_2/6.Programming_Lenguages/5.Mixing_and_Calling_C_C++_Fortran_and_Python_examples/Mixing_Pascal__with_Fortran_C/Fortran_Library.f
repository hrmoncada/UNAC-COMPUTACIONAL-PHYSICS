      subroutine F_Sqr(x,y)
      real*8 x, y
      y = x * x
      return
      end
      
      subroutine NoUnderscores
      integer i
      write(6,*) 'Fortran: NoUnderscores.'
      return
      end
      
      subroutine F_modulo(i,j,k)
      integer i,j,k
      k = MOD(i,j)
      return
      end
      
      subroutine F_cube(x,y)
      real*4 x, y
      y = x * x * x
      return
      end
      
      subroutine F_hello
      real*4 x
      write(6,*) 'Fortran: F_Hello, enter a number:'
      read(5,*) x
      write(6,*) 'Fortran: you entered ', x
      return
      end
      
      subroutine F_call (aprocedure)
      external aprocedure
      integer i,j
      i = 1
      j = 2
      write(6,*) 'Fortran: Calling aprocedure.'
      call aprocedure(i,j)
      return
      end
      
      subroutine F_strings (a_string,a_integer,b_string,a_real)
      integer a_integer
      real*4 a_real
      character*(*) a_string, b_string
      write(6,*) 'Fortran: F_string, ',a_string,', ',b_string
      return
      end;
      
