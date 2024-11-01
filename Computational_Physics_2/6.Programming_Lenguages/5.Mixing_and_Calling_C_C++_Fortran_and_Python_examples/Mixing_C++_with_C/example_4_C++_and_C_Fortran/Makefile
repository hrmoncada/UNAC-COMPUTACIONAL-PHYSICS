$(info Mixing Code in C, C++, and FORTRAN )
compile:
# Compile the C++ code into object file as:
	g++ -c main.cpp  cppfunction.cpp	
# Compile the C code into object file as:
	gcc -c cfunction.c		
# Compile the Fortran90  code into object file as:
	gfortran -c f90function.f90	
link: # Link the object files with g++ as:
	g++ -o out  main.o f90function.o cppfunction.o cfunction.o -lgfortran
run: # Execute out
	./out
clean:
	rm -f *.o  out
