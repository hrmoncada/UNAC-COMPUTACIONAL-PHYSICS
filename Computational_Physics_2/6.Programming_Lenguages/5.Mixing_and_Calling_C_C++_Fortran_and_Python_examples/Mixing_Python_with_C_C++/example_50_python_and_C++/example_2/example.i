/* example.i */
%module example
%{
/* Put header files here or function declarations like below */
extern int fact(int n);
%}

extern int fact(int n);
