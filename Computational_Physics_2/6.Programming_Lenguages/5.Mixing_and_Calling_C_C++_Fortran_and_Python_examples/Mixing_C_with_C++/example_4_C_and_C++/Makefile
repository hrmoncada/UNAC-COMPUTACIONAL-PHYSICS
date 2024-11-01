$(info Mixing Code in C, C++, and FORTRAN )
compile:
# Compile the C++ code into object file as:
	g++ -c print.cpp 
# Compile the C code into object file as:
	gcc -c c_main.c sum.c
link: # Link the object files with g++ as:
	g++ -o out sum.o print.o c_main.o
run: # Execute out
	./out
clean:
	rm -f *.o  out .*-swp
