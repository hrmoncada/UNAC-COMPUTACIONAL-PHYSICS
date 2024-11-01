#include <iostream> // std::cout, std::endl

#include "prod.h" // C header, for prod_Int, prod_Float

using namespace std;

// C
void print_prod(int a, int b) {
    cout << a << " * " << b << " = " << prod_Int(a, b) << endl;
}

void print_prod(float a, float b) {
    cout << a << " * " << b << " = " << prod_Float(a, b) << endl;
}

// C++
extern "C" void print_prod_Int(int a, int b) {
    print_prod(a, b);
}

extern "C" void print_prod_Float(float a, float b) {
    print_prod(a, b);
}
