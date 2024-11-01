c   This Fortran Demonstration file provided by Peter Hurst
c   of Harvard University High Energy Physics Laboratory.
c
c
c	This is supposed to be a piece of standalone code 
c	which will generate fake straight line "data" and 
c	then use MINUIT to fit the a line to the data.  
c
c	The process is as follows:
c	  Declare all the variables
c	  Set aside a piece of named, protected memory
c	  Generate the fake data and stick it into the 
c		protected memory
c	  Initialize MINUIT
c	  Describe the variables (slope and intercept) that 
c		we want MINUIT to use
c	  Make the MINUIT call which does the minimization
c	  Ask MINUIT to return the slope and intercept values
c	  Write the values both to the screen and to a file.
c
c	Generally speaking, comments refer to the code 
c	lines which immediately follow.  
c
c	Also, while I think about it, FORTRAN isn't 
c	case-sensitive, but I try to use case consistently.
c	MINUIT, being very old, sometimes looks better when 
c	parameters are in upper case.  It's only tradition,
c	not function.     
c	=====================================================
c	And here we go - 

c
c	This tells the compiler that we will declare ALL the 
c	variables.  Otherwise it assumes that variables starting 
c	with the letters i,j,k,l,m, and n are integers and everything 
c	else is a real.  I generally respect the i-n are integers 
c	rule, though.  
c	=============================================================
	implicit none

c
c	A simple counting index and an error flag
c	=========================================
	integer i, ierr
c
c	Some crazy integer that MINUIT passes back and 
c	forth.  I have no idea what it does, but MINUIT likes it.
c	=========================================================
	integer icondn

c
c	Variables used to define the parameters that MINUIT will 
c	try to fit.  They include parameter names, initial 
c	guesses for the parameters, a "step" size, and low and 
c	high limits for the parameter.  
c	These character variables have a maximum of 9 characters.
c	Declare the other values to be "double precision" (real*8).
c	Apparently this version of MINUIT likes to have its variables
c	all double precision - if they're *not*, it gets into nasty 
c	type mismatch problems and segmentation faults.  Hmm...
c	=============================================================
	character*9 name1, name2
	real*8 guess_s, guess_i, step, lowlim, hilim
c
c	Define their values at compile time through 'data' statements.
c	This is just a handy way of initializing the variables without
c	typing executable lines of code.  
c	==============================================================
	data name1 /'SLOPE'/, name2 /'INTRCPT'/
	data guess_s /3.14159/, guess_i /-2.46801/
	data step /0.1/, lowlim /-10.0/, hilim /50.0/

c
c	These are my fake datapoints; arrays of x values, y values, and 
c	errors.  I also want to keep track of how many points I'm 
c	using (up to a maximum of 100)
c	===============================================================
	integer npoints
	real x(100), y(100), err(100)

c
c	This declares a "common block" - a piece of protected memory 
c	referred to by a name (mydata) that I can use to store variables 
c	that I want to be able to access in multiple subroutines
c	================================================================ 
	common/mydata/ npoints, x, y, err

c
c	FCN and FUTIL are utility subroutines that MINUIT uses.  MINUIT 
c	demands that these two subroutines exist, and that they have 
c	the names FCN and FUTIL.  (FCN is the function which is 
c	actually minimized, e.g. a chi-square, while FUTIL is just 
c	a utility routine.  I've never used FUTIL).  Declaring them 
c	"external" tells the compiler that they're subroutines and 
c	that it can worry about them later
c	================================================================
	external fcn, futil


c
c	Now for the actual executable lines of code.
c
c	Here I generate the fake data, first defining npoints then 
c	looping from 1 to npoints.  The counting integer, i, is 
c	cast as a real and assigned to be the x value of the 
c	data point.  y is given by y = mx + b, and an error 
c	is arbitrarily assigned. 
c	==========================================================
	npoints = 20
	do i=1,npoints
	  x(i) = float(i)
	  y(i) = 3.83478*x(i) + 8.15319
	  err(i) = 0.123
	end do

c
c	Here we initialize MINUIT. The three numbers tell it what to  
c	do with interactive i/o.  5 is the logical unit number for 
c	the keyboard, so it will expect any necessary interactive 
c	stuff to be typed (though by default with this particular 
c	piece of code you won't have to type anything).  6 is the 
c	logical unit number for the monitor output, so it'll send 
c	its output to the screen.  7 is the standard number for 
c	error output.  God knows what happens to it.
c
c	If you change these numbers, MINUIT will try to interact 
c	with files.  This is possible, but a pain in the butt.
c	=============================================================
	call mninit(5,6,7)

c
c	Here we define the two parameters (slope and intercept) that 
c	we want MINUIT to vary during the fit.  MINUIT wants to 
c	know which parameter it is (1,2,3...), its name (to make it 
c	easier for the pesky humans), an initial guess as to its 
c	likely value, the size of the initial "steps" it will take 
c	when varying the parameter, hard low and high limits on the 
c	parameter (it won't vary it outside this range), and an error 
c	word that it can use if it's unhappy.  (Though I ignore the 
c	error flags.)
c	=============================================================
	call mnparm(1,name1,guess_s,step,lowlim,hilim,ierr)
	call mnparm(2,name2,guess_i,step,lowlim,hilim,ierr)

c   This Fortran Demonstration file provided by Peter Hurst
c   of Harvard University High Energy Physics Laboratory.
c
c
c	This call tells MINUIT to go off and execute a command.  
c	In this case, the command that it's executing is 'SIMPLEX', 
c	which means to use the simplex algorithm to minimize 
c	the function in FCN.  Other commands are possible, and 
c	my typical MINUIT routines use many MNCOMD calls.
c	===========================================================
	call mncomd(fcn,'SIMPLEX',icondn,futil)

c
c	This is a little strange.  MINUIT uses lots of internal 
c	variables to which the average user has no access.  In 
c	particular, the user has no access to the results of the 
c	fit, which is slightly non-optimal.  It *usually* leaves the 
c	results in a particular array, but there's no real guarantee 
c	that the contents of this array are correct. 
c
c	What this 'CALL 3' thing does is to load the correct 
c	results into an array which is accessible inside the FCN 
c	subroutine.  It then calls FCN with the parameter iflag set 
c	to 3.  Users can then output the results from within the 
c	FCN subroutine.  Welcome to 1960's fortran programming.  
c	============================================================
	call mncomd(fcn,'CALL 3',icondn,futil)

c
c	This next call allows you to go in and give MINUIT 
c	interactive commands from the keyboard.  It's sometimes 
c	useful if you see that MINUIT is doing something wacky 
c	and you want to take control and drive it into a more 
c	reasonable pattern of behavior.  I've commented it out, 
c	but you can play with it if you'd like.
c	=======================================================
c	call mnintr(fcn,futil)


c
c	And that's all.
c	===============
	STOP
	END


c
c	Here is the FCN subroutine, the MINUIT workhorse. 
c	It contains the function to be minimized, and also allows 
c	the user to do input and output, if necessary.  It's one 
c	of two subroutines that MINUIT calls that allow the user 
c	some kind of control of what happens.  (The other 
c	subrouine, FUTIL, has never been particularly useful to 
c	me).  
c
c	FCN (and MINUIT in general) is a little like Kabuki theater - 
c	there are rigidly prescribed forms which must be observed, 
c	though there is little apparent reason to justify or explain 
c	why something is done the way that it is.  Alas.
c	============================================================
	subroutine fcn(npar,grad,fval,xval,iflag,futil)

c
c	Again, I'll explicitly decalare all the variables to the 
c	compiler.
c	========================================================
	implicit none

c
c	Take care of the parameters passed through the function 
c	call
c	=======================================================
	integer npar, iflag
c
c	Here I'm declaring these variables to be double precision
c	i.e. twice as many bytes as a standard real.  Also, the 
c	arrays grad and xval are declared to have indeterminate 
c	length (*).  
c	=========================================================
	real*8 grad(*), fval, xval(*)
c
c	And again, ignore FUTIL
c	=======================
	external futil

c
c	Declare the variables in the named, protected memory
c	====================================================
	integer npoints
	real x(100), y(100), err(100)
	common/mydata/ npoints, x, y, err

c
c	Now some utility variables
c	I'll use double precision everwhere.  Even 
c	though the data itself is single precision
c	the compiler will cast the data into the 
c	correct type.
c	==========================================
	integer i
	real*8 slope, intercept, chisq, ytest

c
c	MINUIT provides the current values of the parameters 
c	it is varying in the xval array.  If these parameters 
c	are changed by the user in midstream chaos results.  
c	So, I protect them by transferring them to utility 
c	variables.
c	=====================================================
	slope = xval(1)
	intercept = xval(2)

c
c	initialize the chi-square to zero
c	(the 'd0' part tells it that I want 
c	this double precision ('d') variable 
c	to be zero to umpteen decimal places)
c	=====================================
	chisq = 0.0d0

c
c	Now, loop through all the data points and 
c	sum up the chi-square.  
c	x(i), y(i), and err(i) are simple reals, 
c	not double precision, but the compiler 
c	will cast them correctly.  
c	=========================================
	do i=1,npoints
	  ytest = slope*x(i) + intercept
	  chisq = chisq + ((ytest-y(i))**2/err(i)**2)
	end do
c
c	fval is the actual quantity that MINUIT minimizes.
c	Transfer the chi-square into it
c	==================================================
	fval = chisq

c
c	And that's it for the minimization.  Here we want 
c	to do some output with the results.  The 'CALL 3' 
c	command transfers the current best fit into the 
c	xval array and calls FCN with iflag set equal to 3.
c	If the iflag variable is 3, it's safe to output the 
c	results.
c	===================================================
	if (iflag.eq.3) then
	  slope = xval(1)
	  intercept = xval(2)

c
c	  Here we output the results to the screen (logical 
c	  unit 6).  The '*' tells the compiler to use the 
c	  standard output format.
c	  =================================================
	  write(6,*) 'slope = ', slope, ' intercept = ', intercept
c
c	  and now some output to a file - using logical unit 23 sends 
c	  the output to a file which, by default, is named 'fort.23'.
c	  ===========================================================
	  write(23,*) 'Results of MINUIT fit'
	  write(23,*) 'intercept = ', intercept, ' slope = ', slope

	endif

c
c	And that's all
c	==============
	return
	end


c
c	The useless FUTIL subroutine.  This must exist, but
c	it doesn't need to do anything useful.  Here I just 
c	do something harmless so that the compiler doesn't 
c	complain.
c	===================================================
	subroutine futil()
	implicit none
	integer ierr
	ierr = 0
	return
	end
