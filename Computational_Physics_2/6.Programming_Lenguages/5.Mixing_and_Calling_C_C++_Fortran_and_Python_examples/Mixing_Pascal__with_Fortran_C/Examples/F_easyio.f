c   This Fortran Demonstration file provided by Peter Hurst
c   of Harvard University High Energy Physics Laboratory.
c
c	The write statement writes stuff to a logical unit 
c	number, which, in turn, is assigned to a device or a 
c	file.  6 is the logical unit number for the screen.
c	The * in the write statement tells the compiler to 
c	choose the most convenient format for the variable i/o, 
c	and the stuff between single quotes is written verbatim.
c
c	The read statement reads stuff in from a logical unit 
c	number or device.  5 is the logical unit number for the 
c	keyboard.  Here the * allows the user to input stuff 
c	pretty much however he likes, provided that subsequent 
c	entries on the same line are separated by spaces.  
c	The * is almost always used for terminal input, since 
c	it's hard for the common user to remember precisely 
c	how to format his responses.
c
c	Logical unit numbers other than 5, 6, or 7 (7 is for 
c	standard error) can be used to read and write to files 
c	in pretty much the same way.  One can use format statements
c	if one wants to control exactly how the output looks.  
c	I've included a few examples below.
c	===========================================================


	implicit none

	integer i, j, k
	real a, b, arr(10)
	character*10 c

c
c	here I just fill an array with numbers
c	======================================
	do i=1,10
	  arr(i) = i*(1.0000001)
	end do


	write(6,*) 'Here I prompt you for an integer'
	write(6,*) 'Just type one in and hit return'
	read(5,*) i
	write(6,*) 'You typed ', i

	write(6,*) '   '
	write(6,*) '   '
	write(6,*) 'Now, for something more complex'
	write(6,*) 'Multiple inputs per line are possible'
	write(6,*) 'Provided they are separated by spaces'
	write(6,*) '   '
	write(6,*) 'Type in a real '
	write(6,*) 'then up to 10 characters '
	write(6,*) 'then an integer '
	write(6,*) '*all on one line, separated by spaces*' 
	write(6,*) 'and hit return'
	read(5,*) a, c, j
	write(6,*) '   '
	write(6,*) 'The character string was ',c
	write(6,*) 'The integer was ', j
	write(6,*) 'The real was ', a

	write(6,*) '   '
	write(6,*) '   '
	write(6,*) '   '
	write(6,*) 'Here is an uncontrolled format'
	write(6,*) (arr(k),k=1,10)
	write(6,*) '   '
c
c	here the 123 in write(6,123) refers to the line number 
c	of a format statement.  The format statement in question 
c	tells the compiler to prepare 10 repetitions of 2 spaces 
c	(x denotes a space) followed by a real which uses 6 total 
c	characters and has two characters behind the decimal point.
c	===========================================================
	write(6,*) 'And a more beautiful format'
	write(6,123) (arr(k),k=1,10)
 123	format(10(2x,f6.2))

c
c	Finally, these two lines will write the array to logical 
c	unit number 18 which should direct stuff into a file 
c	called "fort.18".  Once the format statement is defined 
c	I can refer to it over and over again.  
c	========================================================
	write(18,*) 'My array is '
	write(18,123) (arr(k),k=1,10)

	stop
	end
