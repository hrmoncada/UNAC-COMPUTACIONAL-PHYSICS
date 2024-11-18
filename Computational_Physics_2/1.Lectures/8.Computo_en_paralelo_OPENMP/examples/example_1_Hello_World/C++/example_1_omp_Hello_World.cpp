/* https://stackoverflow.com/questions/33357029/using-openmp-with-clang
$ g++ -fopenmp -o test test.cpp
$ ./test
$./clang++ -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -fopenmp=libiomp5 -o test test.cpp
$ clang++ -fopenmp -o test test.cpp
$ ./test

https://iscinumpy.gitlab.io/post/omp-on-high-sierra/
clang -Xpreprocessor -fopenmp -lomp myfile.cxx
clang -Xpreprocessor -fopenmp -lomp -I"$(brew --prefix libomp)/include" -L"$(brew --prefix libomp)/lib" myfile.cxx

*/

#include <iostream>
#include <omp.h>
int main() {
    #pragma omp parallel num_threads(4)
    {
        #pragma omp critical
        std::cout << "tid = " << omp_get_thread_num() << std::endl;
    }
}
