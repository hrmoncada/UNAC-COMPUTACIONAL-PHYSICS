/******************************************************************************
 * * FILE: serial.c
 * * DESCRIPTION:
 * *   Calculates the value of pi using a serial implementation.
 * *
 * * HOW TO COMPILE:
 * *   gcc -lm serial.c
 * * HOW TO RUN:
 * *    ./a.out
 * *
 * * AUTHOR: Ishan Thilina Somasiri
 * ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

/**
A random number generator. 
Guidance from from http://stackoverflow.com/a/3067387/1281089
**/
float randNumGen(){

   int random_value = rand(); //Generate a random number   
   float unit_random = random_value / (float) RAND_MAX; //make it between 0 and 1 
   return unit_random;
}

int main(int argc, char *argv[])
{
   
   srand ( time(NULL) );         //initiate random seed
   float in_count=0;
   float tot_count=0;
   int tot_iterations=10000000;
   int counter=0;
   
   for(counter=0;counter<tot_iterations;counter++){
      float x = randNumGen();
      float y = randNumGen();
      
      float result = sqrt((x*x) + (y*y));
      
      if(result<1){
         in_count+=1;         //check if the generated value is inside a unit circle
      }
      tot_count+=1;
      
   }

   float pi=4*in_count/tot_count;
   printf("The value of Pi is : %f\n",pi);
   
   
   
}
