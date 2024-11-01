// C++ subprogram to find product of array elements.
#include <iostream>
#include <vector>

#include "pass_by_ref.h" // C header

using namespace std;

double cpp_array_product(double *a, double *b, double *c, int n) {
    int result = 1;
    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
        result = result * c[i];
    }    
    return result;
}
