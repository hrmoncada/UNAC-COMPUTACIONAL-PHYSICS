/*http://www-h.eng.cam.ac.uk/help/tpl/languages/mixinglanguages.html
Put extern "C" here to avoid name-mangling. Alas,  extern "Fortran" is unavailable.
Note that g77 adds an underscore to names so C++ has to add an underscore to the fortran function name!
*/

#include <iostream>

using namespace std;

extern "C" {
    int f90function_(int *i);
}

int main() {
  int i = 2;
  int j = f90function_(&i);
  cout << "return = " << j << endl;
  return 0;
}
