/*
There are two functions with the same name (printSum) that only differ in their parameters’ type: "int" or "float". Function overloading is a C++ feature which isn’t present in C. 
To implement this feature and differentiate those functions, C++ mangles the function name, 
as we can see in their exported symbol name (I’ll only pick what’s relevant from nm’s output):

$ g++ -c print.cpp
$ nm print.o
                 U __cxa_atexit
                 U __dso_handle
                 U _GLOBAL_OFFSET_TABLE_
00000000000001bf t _GLOBAL__sub_I__Z8printSumii
0000000000000145 T printSumFloat
0000000000000121 T printSumInt
                 U sumF
                 U sumI
0000000000000172 t _Z41__static_initialization_and_destruction_0ii
000000000000008b T _Z8printSumff
0000000000000000 T _Z8printSumii
                 U _ZNSolsEf
                 U _ZNSolsEi
                 U _ZNSolsEPFRSoS_E
                 U _ZNSt8ios_base4InitC1Ev
                 U _ZNSt8ios_base4InitD1Ev
                 U _ZSt4cout
                 U _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
0000000000000000 r _ZStL19piecewise_construct
0000000000000000 b _ZStL8__ioinit
                 U _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKct

Those functions are exported (in my system) as :
_Z8printSumff for the float version, and
_Z8printSumii for the int version. 
Every function name in C++ is mangled unless declared as extern "C". 
There are two functions that were declared with C linkage in print.cpp:
printSumInt and printSumFloat.  

Therefore, they cannot be overloaded, or their exported names would be the same since they aren’t mangled. I had to differentiate them from each other by postfixing an Int or a Float to the end of their names.
                 
To see the mangled names like we would see them in C++ source code, 
we can use the -C (demangle) option in the nm command.

$ nm -C print.o
                 U __cxa_atexit
                 U __dso_handle
                 U _GLOBAL_OFFSET_TABLE_
00000000000001bf t _GLOBAL__sub_I__Z8printSumii
0000000000000145 T printSumFloat
0000000000000121 T printSumInt
                 U sumF
                 U sumI
0000000000000172 t __static_initialization_and_destruction_0(int, int)
000000000000008b T printSum(float, float)
0000000000000000 T printSum(int, int)
                 U std::ostream::operator<<(float)
                 U std::ostream::operator<<(int)
                 U std::ostream::operator<<(std::ostream& (*)(std::ostream&))
                 U std::ios_base::Init::Init()
                 U std::ios_base::Init::~Init()
                 U std::cout
                 U std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)
0000000000000000 r std::piecewise_construct
0000000000000000 b std::__ioinit
                 U std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
              
 */

#include <iostream> // std::cout, std::endl

#include "sum.h" // call sumI, sumF

using namespace std;

/*
We also see that our C++ code is calling C code: 
print.cpp is calling sumI and sumF, which are C functions declared as having C linkage in sum.h. 
*/

void printSum(int a, int b) {
    cout << a << " + " << b << " = " << sumI(a, b) << endl;
}

void printSum(float a, float b) {
    cout << a << " + " << b << " = " << sumF(a, b) << endl;
}

extern "C" void printSumInt(int a, int b) {
    printSum(a, b);
}

extern "C" void printSumFloat(float a, float b) {
    printSum(a, b);
}
