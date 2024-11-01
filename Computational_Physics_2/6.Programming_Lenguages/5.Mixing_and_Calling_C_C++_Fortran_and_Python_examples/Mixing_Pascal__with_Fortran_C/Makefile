products: Main.exe

Main.exe: Main.o Fortran_Library.o Pascal_Library.o C_Library.o
	/usr/bin/gcc -o Main.exe Main.o \
		Fortran_Library.o libf2c.a \
		Pascal_Library.o libgpc.a \
		C_Library.o
	
Main.o: Main.c
	/usr/bin/gcc -c -o Main.o Main.c
	
Fortran_Library.o: Fortran_Library.f
	/usr/local/bin/g77 -c -o Fortran_Library.o Fortran_Library.f

Pascal_Library.o: Pascal_Library.p
	/usr/bin/gpc -c -o Pascal_Library.o Pascal_Library.p

C_Library.o: C_Library.c
	/usr/bin/gcc -c -o C_Library.o C_Library.c

clean: 
	rm *.o Main.exe *.gpi
