/* https://stackoverflow.com/questions/145270/calling-c-c-from-python
 * File : example.c 
 
 Building a Python module on Unix:

swig -python example.i
gcc -fPIC -c example.c example_wrap.c -I/usr/local/include/python2.7
gcc -shared example.o example_wrap.o -o _example.so

Usage:

>>> import example
>>> example.fact(5)
120
 
 */
int fact(int n) {
    if (n <= 1) return 1;
    else return n*fact(n-1);
}
