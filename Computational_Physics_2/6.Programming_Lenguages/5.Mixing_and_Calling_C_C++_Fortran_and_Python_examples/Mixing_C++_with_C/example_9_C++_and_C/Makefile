$(info Mixing Code in C++, and C++)
compile:
# Compile the C++ code into object file as:
	g++ -c main.c print_sum.cpp
# Compile the C code into object file as:
	gcc -c sum.c
link: # Link the object files with g++ as:
	g++ -o out sum.o print_sum.o main.o
run: # Execute out
	./out
clean:
	rm -f *.o  out .*-swp
