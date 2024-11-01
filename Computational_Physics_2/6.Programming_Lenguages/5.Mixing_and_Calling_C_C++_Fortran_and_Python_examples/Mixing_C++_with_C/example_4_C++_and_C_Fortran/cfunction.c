#include <stdio.h>

void cfunction(float *a, float *b) {
  *a = 7.0;
  *b = 8.0;
   printf( "cfunction (a, b) = (%f, %f)\n", *a, *b );
}
