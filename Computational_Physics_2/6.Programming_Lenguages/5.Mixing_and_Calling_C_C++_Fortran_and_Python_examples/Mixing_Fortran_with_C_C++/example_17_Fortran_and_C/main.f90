!http://www.lahey.com/nl98apr.htm
! F90CALLC.F90                                                          ! 1
! Copyright 1998 Lahey Computer Systems, Inc.                           ! 2
!                                                                       ! 3
       ml_external GenTable                                             ! 4
       integer gentable,totalf                                          ! 5
       real totalc                                                      ! 6
       common /mycommon/ totalc, totalf                                 ! 7
       integer start, end, table_lines                                  ! 8
                                                                        ! 9
       write(6,1) 'Where should the table start (enter an &
       &integer less than 10) ? '                                       ! 10
       read(5,*) start                                                  ! 11
       write(6,1) 'In Fortran, now calling C'                           ! 12

       table_lines = gentable(start, end)                                 ! 13

       write(6,1) 'Back in Fortran, after calling C'                    ! 14
       write(6,2) 'The table ended at:',end                             ! 15
       write(6,3) 'Total degrees c=',totalc                             ! 16
       write(6,2) 'Total degrees f=',totalf                             ! 17
                                                                        ! 18
       write(6,2) 'Number of lines in table:',table_lines               ! 19
1      format(1x,a)                                                     ! 20
2      format(1x,a,i4)                                                  ! 21
3      format(1x,a,f6.2)                                                ! 22
       end                                                              ! 23
                                                                        ! 24
       block data setmycommon                                           ! 25
       common /mycommon/ totalc, totalf                                 ! 26
       data totalc/0.0/, totalf/0.0/                                    ! 27
       end block data setmycommon                                       ! 28
