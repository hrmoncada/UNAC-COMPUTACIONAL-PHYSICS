! https://sites.science.oregonstate.edu/~landaur/nacphy/ComPhys/MONTE/PRO/pi.src/pi.f
c	calculating pi by throwing stones
c
	PROGRAM stones
	IMPLICIT none
c
c	   declarations
	REAL*8 area, x, y, DRAND48
	INTEGER i, max, pi, seed
c
c	   set parameters (number of stones, seed for generator)
	max = 1000
	seed = 11168
c
c	   open file, set initial value, seed generator
	OPEN(6, FILE='pif.dat')
	pi=0
	call seed48(seed)
c
c	   execute
	DO 10 i=1, max
	   x = DRAND48()*2-1
	   y = DRAND48()*2-1	
	   IF ((x*x + y*y) .LT. 1) THEN
	      pi = pi+1
	   ENDIF
	   area = 4.0 * pi/REAL(i)
	   WRITE(6,*) i, area
 10 	CONTINUE
 	STOP
 	END
 	
