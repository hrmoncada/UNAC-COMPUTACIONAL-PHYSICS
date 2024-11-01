/*https://www.geeksforgeeks.org/how-to-call-c-c-from-python/
 *
g++ -c -fPIC geek.cpp -o geek.o
g++ -shared -Wl,-soname,libgeek.so -o libgeek.so geek.o


*/
#include <iostream>
//#include "geek.h"
using namespace std;

class Geek{
    public:
        void myFunction(){
            cout << "Hello Geek!!!" << endl;
    }
};

int main() {
// Creating an object
     Geek test;

// Calling function
     test.myFunction();

     return 0;
}
