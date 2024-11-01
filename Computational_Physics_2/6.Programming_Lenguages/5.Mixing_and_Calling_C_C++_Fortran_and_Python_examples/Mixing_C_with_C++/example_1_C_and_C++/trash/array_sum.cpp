// C++ subprogram to return array sum and sum of elements in arrays of size n
#include<iostream>
#include <vector>
using namespace std;

double array_sum(vector <double> &a, vector <double> &b, vector<double> &c) {
    double sum = 0.0; // initialize sum
 
// Iterate through all elements and add them to sum
    for (int i = 0; i < n; i++){
         c[i] = a[i] + b[i];
         sum += c[i];
    }
    
    return sum;
}
