/*https://stackoverflow.com/questions/145270/calling-c-c-from-python
g++ -c -fPIC -shared foo.cpp -o libfoo.so
g++ -shared -Wl,-soname,libfoo.so -o libfoo.so  foo.o

 */
#include <iostream>

using namespace std;

class Foo{
    public:
        void bar(){
            cout << "Hello" << endl;
        }
};
