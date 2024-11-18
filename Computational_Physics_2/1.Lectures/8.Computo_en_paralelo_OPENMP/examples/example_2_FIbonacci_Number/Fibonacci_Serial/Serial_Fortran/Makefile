CCOMP ?= gfortran
CFLAGS ?= -fopenmp -O3 -g -Wall

all:
	$(CCOMP) fibonacci_serial_1.f90 $(CFLAGS) -S
	$(CCOMP) fibonacci_serial_1.f90 $(CFLAGS) -o FIB.x

clean:
	rm -f *.s *.o *.optrpt FIB.x
