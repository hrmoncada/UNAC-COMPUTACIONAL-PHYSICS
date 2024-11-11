! http://www.mathcs.emory.edu/~cheung/Courses/561/Syllabus/92-MPI/intro-f.html
program Hello
   implicit none

   include 'mpif.h'

   integer :: mpierror, numprocs
   integer :: i, myid
   integer status(MPI_STATUS_SIZE)

   character*128 buff              ! String...


   call MPI_Init(mpierror)
   call MPI_Comm_size(MPI_COMM_WORLD, numprocs, mpierror)
   call MPI_Comm_rank(MPI_COMM_WORLD, myid, mpierror)


   if ( myid == 0 ) then 
      !! Master processor

      print *, "We have ", numprocs, " processor"

      do i = 1, numprocs-1
         write ( buff , *) "Hello ", myid

         call MPI_Send(buff, 128, MPI_CHARACTER, i, 0, MPI_COMM_WORLD, &
                       mpierror)
      end do

      do i = 1, numprocs-1

         call MPI_Recv(buff, 128, MPI_CHARACTER, i, 0, MPI_COMM_WORLD, &       
                     status, mpierror)

         write (6, *) buff
      end do

   else 
      !! Slave processors

      call MPI_Recv(buff, 128, MPI_CHARACTER, 0, 0, MPI_COMM_WORLD, &
                     status, mpierror);

      write(buff, *) "Hello 0, Processor ", myid, &
              " is present and accounted for !"

      call MPI_Send(buff, 128, MPI_CHARACTER, 0, 0, MPI_COMM_WORLD, &
                     mpierror);
   end if


   call MPI_Finalize(mpierror)

 end program
