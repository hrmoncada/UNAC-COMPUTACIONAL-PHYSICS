#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void stringing_(char* s, int len) {
   char *str = (char*)malloc(len+1);
   strncpy(str,s,len);
   str[len]='\0';
   printf("%s\n",str);
}
