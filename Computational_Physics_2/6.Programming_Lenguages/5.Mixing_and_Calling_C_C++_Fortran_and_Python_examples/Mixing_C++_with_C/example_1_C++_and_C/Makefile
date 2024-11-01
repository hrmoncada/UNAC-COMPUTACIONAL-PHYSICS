$(info Mixing Code in C++, and C++)
compile:
# Compile the C code into object file as:
	gcc -c cfunction.c
# Compile the C++ code into object file as:
	g++ -c  main.cpp Fredd.cpp
link: # Link the object files with g++ as:
	g++ -o out main.o Fredd.o cfunction.o 
run: # Execute out
	./out
clean:
	rm -f *.o  out .*-swp
