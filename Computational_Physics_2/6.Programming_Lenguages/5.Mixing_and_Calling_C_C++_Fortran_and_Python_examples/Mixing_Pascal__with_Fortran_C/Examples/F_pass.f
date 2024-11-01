c   This Fortran Demonstration file provided by Peter Hurst
c   of Harvard University High Energy Physics Laboratory.
c
c
c	This is just a piece of toy code to investigate the 
c	way in which the compiler handles parameters passed 
c	into (and out of) subroutines.
c	===================================================

	implicit none
	integer i, j, k
	integer lun
c
c	give these guys simple assignments
c	==================================
	i=1
	j=2
	k=3
c
c	try to protect the output logical unit number
c	=============================================
	lun = 6

c
c	The initial '1' just tells me this is the first time 
c	I'm calling the mixing code.  Call it here by passing 
c	it variables
c	=====================================================
	call mix(1,i,j,k,lun)
c
c	Call it again (with initial counter '2'), this time 
c	passing it constants
c	===================================================
	call mix(2,1,2,3,lun)

c
c	now, just make sure we haven't screwed up the 
c	value of '1'
c	=============================================
	i=1
	j=2
	k=3
	write(lun,*) 'last ',i, j, k, 2*i, 2*j, 2*k

	stop
	end	

c
c	This is the "mixing" routine.  It merely does 
c	a circular shift of the three variables
c	=============================================
	subroutine mix(ilabel, ii, jj, kk, lun)

	implicit none
	integer ilabel, ii, jj, kk, lun
	integer itemp

	itemp = ii
	ii = jj
	jj = kk
	kk = itemp

c
c	write out the results
c	=====================
	write(lun,*)ilabel, ii, jj, kk

	return
	end
