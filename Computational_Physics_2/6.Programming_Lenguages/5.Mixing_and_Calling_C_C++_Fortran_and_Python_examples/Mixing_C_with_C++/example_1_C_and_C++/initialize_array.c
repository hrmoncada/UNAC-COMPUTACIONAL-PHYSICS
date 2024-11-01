
#include "pass_by_ref.h" // C header

double c_initialize_array(double *a, double *b, int n){ 
    for(int i = 0; i < n; i++){
      a[i] = 1.0;
      b[i] = 2.0;
    }    
 } 
