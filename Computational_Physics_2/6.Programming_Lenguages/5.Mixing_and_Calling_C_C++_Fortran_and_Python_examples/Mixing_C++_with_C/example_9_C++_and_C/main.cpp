/*https://www.toptal.com/c-plus-plus/c-plus-plus-understanding-compilation
https://www.oracle.com/technical-resources/articles/it-infrastructure/mixing-c-and-cplusplus.html#:~:text=Linking%20the%20Program,-At%20one%20time&text=Even%20if%20your%20program%20is,driver%2C%20to%20do%20the%20linking.
$ gcc -c main.c
$ nm main.o
                 U _GLOBAL_OFFSET_TABLE_
0000000000000000 T main
                 U printSumFloat
                 U printSumInt

 */
#include <iostream> // std::cout, std::endl

using namespace std;

#include "print_sum.hpp"

/*The two functions with the same name "printSum" that only differ in their parameters’ type: "int" or "float". Function overloading is a C++ feature which isn’t present in C.  */
int main(int argc, char* argv[]) {
    cout << "Begin Program" << endl;

    printSum(1, 2);
    printSum(1.5f, 2.5f);

    printSumInt(3, 4);
    printSumFloat(3.5f, 4.5f);

    cout << "end Program" << endl;

    return 0;
}
