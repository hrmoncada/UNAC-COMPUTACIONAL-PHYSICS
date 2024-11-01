/* 
$ gcc -c sum.c
$ nm sum.o
0000000000000018 T sumF
0000000000000000 T sumI

No symbols are imported and two symbols are exported: sumF and sumI. 
Those symbols are exported as part of the .text segment (T), 
so they are function names, executable code.
 */
int sumI(int a, int b) {
    return a + b;
}

float sumF(float a, float b) {
    return a + b;
}
