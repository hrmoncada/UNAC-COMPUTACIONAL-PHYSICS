/* http://mordenchina.blogspot.com/2007/06/tutorial-using-cc-and-fortran-together.html
 Compile:

* f77 -c testF.f
* g++ -c testC.cpp
* g++ -o test testF.o testC.o -lg2c

Run: ./test

ii= 5 ff= 5.500
 */
#include

using namespace std;

extern"C" {
void fortfunc_(int *ii, float *ff);
}

main()
{

int ii=5;
float ff=5.5;

fortfunc_(&ii, &ff);

return 0;
}
