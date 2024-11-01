$(info Mixing Code in C, C++, and FORTRAN )

# Compilers
CC=gcc
CPP=g++
FOR=gfortran

# Source code
CPPSOURCES=main.cpp 
CSOURCES=
F90SOURCES=f90function.f90 
# object files
OBJECTS=main.o f90function.o 
# FLAGS variable sets compile flags
# qnoopt/-O0 Fast compilation, debuggable code, conserved program semantics.
#  -g       Compile with debug information
#  -Wall    Give verbose compiler warnings
#  -Wextra  In conjunction with -Wall, gives warnings about even more potential problems.
#  -O0      Do not optimize generated code
#  -O2      (same as -O) Comprehensive low-level optimization; partial debugging support.
#  -O3      More extensive optimization; some precision trade-offs.
#  -O4 and -O5 Interprocedural optimization; loop optimization; automatic machine tuning.
#  -std=gnu99   Use the GNU99 standard C language definition
#  -std=gnu++11 Use the GNU11 standard C++ compiler
#  -std=f2008
#  -std=c99/-std=c11 
#  -std=c++17 
CFLAGS=-g -Wall -O0 -std=gnu99
CPPFLAGS=-g -Wall -O0 -std=gnu++11
FFLAGS=-g -Wall -O0 -std=f2008
MATHLIB=-lm
LINKLIB=-lgfortran

# -c flag says to generate the object file,
# -o $@ says to put the output of the compilation in the file named on the left side of the : 
# $< is the first item in the dependencies list, and the CFLAGS macro is defined as above.
# .PHONY rule keeps make from doing something with a file named clean.

compile:
# # Compile the C code into object file as:
# 	$(CC) -c $(CSOURCES)	
# Compile the C++ code into object file as:
	$(CPP) -c $(CPPSOURCES)		
# Compile the Fortran90  code into object file as:
	$(FOR) -c $(F90SOURCES)	
out: # Linking the object files as:
	$(CPP) -o $@ $(OBJECTS) $(LINKLIB)
run: # Execute out
	./out
.PHONY: clean
clean:
	rm -f *.o  out
