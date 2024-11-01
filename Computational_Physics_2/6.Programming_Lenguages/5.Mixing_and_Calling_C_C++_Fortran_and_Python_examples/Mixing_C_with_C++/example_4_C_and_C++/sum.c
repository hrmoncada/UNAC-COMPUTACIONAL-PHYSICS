/* 
$ gcc -c sum.c
$ nm sum.o
0000000000000018 T sumF
0000000000000000 T sumI

No symbols are imported and two symbols are exported: sumF and sumI. 
Those symbols are exported as part of the .text segment (T), 
so they are function names, executable code.

If other (both C or C++) source files want to call those functions,
they need to declare them before calling.

The standard way to do it is to create a header file that declares them
and includes them in whatever source file we want to call them.
The header can have any name and extension. I chose sum.h:
 */
int sumI(int a, int b) {
    return a + b;
}

float sumF(float a, float b) {
    return a + b;
}
