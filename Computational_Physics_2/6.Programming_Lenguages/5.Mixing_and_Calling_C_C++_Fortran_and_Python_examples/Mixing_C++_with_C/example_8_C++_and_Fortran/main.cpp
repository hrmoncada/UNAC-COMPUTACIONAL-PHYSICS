/*
http://www.yolinux.com/TUTORIALS/LinuxTutorialMixingFortranAndC.html
https://stackoverflow.com/questions/7264525/linking-fortran-and-c-objects-files

You should find file libgfortran.* (e.g. with locate of find / -name "libgfortran.*"; or in windows-way Win+g, F3 or any file manager), record the path where it is and do

$ g++ -o out f90function.o main.o -LPATH_RECORDED -lgfortran

where PATH_RECORDED is the path.

Try this lib list (got it from my mingw gfortran with -v option)

$ g++ -o out f90function.o main.o -LPATH_RECORDED -lgfortran -lmingw32 -lgcc_s -lgcc -lmoldname  -lmingwex -lmsvcrt

*/

#include <iostream>

using namespace std;

extern"C" {
    void fortfunc_(int *ii, float *ff);
    int  square_(int *ii);
}

int main() {

   int ii = 5;
   float ff = 5.5;

   fortfunc_(&ii, &ff);

   int jj = square_(&ii);

   cout << "return = " << jj << endl;

   return 0;
}

