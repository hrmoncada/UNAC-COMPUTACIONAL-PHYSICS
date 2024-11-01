/*
https://sites.google.com/a/gokliya.net/www/ccallingfortranapiwithderivedtypes
 */
#include <stdio.h>
#include "config.h"

int main() {
 
  /* encapsulate Fortran derived type as an array of doubles */
  double self[10];
  int n = 10;

  float a[ ] = {1., 2., 3., 4. , 5., 6., 7.,  8. , 9., 0.};
  float b[10];

 
  foo_new_(self, &n);
  foo_setx_(self, a, &n);
  foo_getx_(self, b, &n);

  for (int i = 0; i < n; ++i) printf("i = %d b = %f \n", i, b[i]);

  return 0;
 } 
