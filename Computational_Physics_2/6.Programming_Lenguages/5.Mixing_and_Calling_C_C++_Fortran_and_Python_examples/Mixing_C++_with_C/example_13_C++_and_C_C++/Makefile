$(info Mixing Code in C++, and C++)
compile:
# Compile the C++ code into object file as:
	g++ -c main.cpp cppfunction.cpp
# Compile the C code into object file as:
	gcc -c cfunction.c
link: # Link the object files with g++ as:
	g++ -o out  main.o cfunction.o cppfunction.o
run: # Execute out
	./out
clean:
	rm -f *.o  out .*-swp
