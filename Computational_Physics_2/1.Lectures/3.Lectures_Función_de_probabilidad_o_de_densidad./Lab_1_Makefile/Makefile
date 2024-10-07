# Copy Makefile file
# cp Makefile_2 Makefile
# make -f Makefile_2

CC = gcc
CFLAGS = -I.
DEPS = hello_make.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: hello_make.o hello_func.o 
	$(CC) -o out hello_make.o hello_func.o 

run:
	./out

clean:
	rm -f *.o  out  .*
