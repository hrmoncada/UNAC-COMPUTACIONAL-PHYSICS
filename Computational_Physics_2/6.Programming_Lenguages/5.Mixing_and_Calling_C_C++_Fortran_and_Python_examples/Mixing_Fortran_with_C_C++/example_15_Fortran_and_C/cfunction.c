#include <stdio.h>

void doubling_(int* i) {
  int j = *i;
  *i = j*2;
  printf("suare = %d\n",*i);
}
