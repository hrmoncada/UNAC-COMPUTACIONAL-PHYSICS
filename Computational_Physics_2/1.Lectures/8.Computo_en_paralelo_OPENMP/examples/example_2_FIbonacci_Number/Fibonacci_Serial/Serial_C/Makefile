CCOMP ?= gcc 
CFLAGS ?= -fopenmp -O3 -g -Wall

all:
	$(CCOMP) fibonacci_serial_1.c $(CFLAGS) -S
	$(CCOMP) fibonacci_serial_1.c $(CFLAGS) -o FIB.x

clean:
	rm -f *.s *.o *.optrpt FIB.x
