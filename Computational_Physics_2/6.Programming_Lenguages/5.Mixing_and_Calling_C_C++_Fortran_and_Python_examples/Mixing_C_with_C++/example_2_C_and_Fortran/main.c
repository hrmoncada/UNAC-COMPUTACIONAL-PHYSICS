/*
 http://www.math.chalmers.se/Math/Grundutb/CTH/tma881/0708/Assignments/Mixing_C_Fortran.html
 */
#include <stdio.h>

#include "random_vec.h"

// void extern ranvec_(double *, int *);

int main() {
  int n = 5;
  double a[5];

  ranvec_(a, &n);

  printf("a = %f, %f, %f, %f, %f\n", a[0], a[1], a[2], a[3], a[4]);

  return 0;
}
