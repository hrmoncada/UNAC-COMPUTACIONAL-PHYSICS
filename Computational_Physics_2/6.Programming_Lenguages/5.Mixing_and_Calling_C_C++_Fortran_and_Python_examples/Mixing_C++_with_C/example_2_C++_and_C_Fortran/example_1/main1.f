! https://www.ibm.com/support/knowledgecenter/SSGH4D_15.1.3/com.ibm.xlf1513.aix.doc/proguide/cwrap.html
       program main

       integer idim,idim1

       idim = 35
       idim1= 45

       write(6,*) 'Inside Fortran calling first C function'
       call cfun(idim)
       write(6,*) 'Inside Fortran calling second C function'
       call cfun1(idim1)
       write(6,*) 'Exiting the Fortran program'
       end


