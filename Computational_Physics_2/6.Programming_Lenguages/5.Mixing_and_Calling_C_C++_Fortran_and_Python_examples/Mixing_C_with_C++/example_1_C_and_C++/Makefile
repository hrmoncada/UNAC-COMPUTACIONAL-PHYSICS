$(info Mixing Code in C, C++, and FORTRAN )
compile:
# Compile the C++ code into object file as:
	g++ -c  print_prod.cpp pass_by_ref.cpp 
# Compile the C code into object file as:
	gcc -c  main.c prod.c swap.c
link: # Link the object files with g++ as:
	g++ -o out main.o print_prod.o prod.o pass_by_ref.o  swap.o
run: # Execute out
	./out
clean:
	rm -f *.o  out .*-swp
