/*https://solarianprogrammer.com/2012/05/11/mixed-language-programming-cpp-11-fortran-2008/

Please note the syntax used at line 50 for sending a C++ STL vector to our Fortran subroutine by reference.
The above codes can be compiled with gcc-4.7 on Linux and Mac or with Visual Studio and Intel Fortran on Windows.
If you save the Fortran code in fortran_matrix_multiply.f90 and C++ in cpp_main_1.cpp you can compile and link them on Unix:


$ gfortran-4.7 -c fortran_matrix_multiply.f90
$ g++-4.7 -c -std=c++11 cpp_main_1.cpp
$ gfortran-4.7 fortran_matrix_multiply.o cpp_main_1.o -lstdc++ -o mix_example.out
$ ./mix_example.out

0.411975 0.886183 0.041323
0.130066 0.576865 0.507137
0.26862 0.938682 0.385561

0.464278 0.317101 0.3179
0.799268 0.0544081 0.744739
0.0202931 0.0940126 0.447147

0.900407 0.182738 0.809419
0.531748 0.120308 0.697726
0.882796 0.172499 0.956869
*/

#include <iostream>
 #include <vector>
 #include <random>
 #include <ctime>

 using namespace std;

//Fortran subroutine definition "translated" to C++
 extern "C" {
    void matrix_multiply_(double *A, int *rows_A, int *cols_A, double *B, int *rows_B, int *cols_B, double *C, int *rows_C, int *cols_C);
}

//Fill a vector with random numbers in the range [lower, upper]
void rnd_fill(vector<double> &V, double lower, double upper) {
//use system clock to create a random seed
    size_t seed (clock());

//use the default random engine and an uniform distribution
     default_random_engine eng(seed);
     uniform_real_distribution<double> distr(lower, upper);

     for( auto &elem : V){
         elem = distr(eng);
     }
 }

//Print matrix V(rows, cols) storage in column-major format
void print_matrix(vector<double> const &V, int rows, int cols) {
     for(int i = 0; i < rows; ++i){
         for(int j = 0; j < cols; ++j){
             cout << V[j * rows + i] << " ";
         }
         cout << endl;
     }
     cout << endl;
 }

int main() {
     size_t N = 3;
     vector<double> A(N * N), B(N * N), C(N * N);

//Fill A and B with random numbers in the range [0,1]:
     rnd_fill(A, 0.0, 1.0);
     rnd_fill(B, 0.0, 1.0);

//Multiply matrices A and B, save the result in C
     int sz = N;
     matrix_multiply_(&A[0], &sz, &sz, &B[0], &sz, &sz, &C[0], &sz, &sz);

//print A, B, C on the standard output
     print_matrix(A, sz, sz);
     print_matrix(B, sz, sz);
     print_matrix(C, sz, sz);

     return 0;
}
