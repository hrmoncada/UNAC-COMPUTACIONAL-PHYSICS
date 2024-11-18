CCOMP ?= icpc
CFLAGS ?= -qopenmp -O3 -g -qopt-report=5

all:
	$(CCOMP) fibonacci_openmp_1.c $(CFLAGS) -S
	$(CCOMP) fibonacci_openmp_1.c $(CFLAGS) -o FIB.x

clean:
	rm -f *.s *.o *.optrpt FIB.x
