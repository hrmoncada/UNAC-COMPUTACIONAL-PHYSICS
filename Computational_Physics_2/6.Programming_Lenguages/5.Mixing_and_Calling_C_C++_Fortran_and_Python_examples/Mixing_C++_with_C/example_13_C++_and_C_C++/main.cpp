/*
 * http://www-h.eng.cam.ac.uk/help/tpl/languages/mixinglanguages.html
 * https://www.oracle.com/technical-resources/articles/it-infrastructure/mixing-c-and-cplusplus.html#:~:text=Linking%20the%20Program,-At%20one%20time&text=Even%20if%20your%20program%20is,driver%2C%20to%20do%20the%20linking.
*/
#include <iostream>

using namespace std;

#include "pass_by_ref.h"

// float cppfunction(float *); // C++ prototype
//  
// extern "C" {
//    int cfunction(int *); // C prototype
// }

int main() {
  cout << "Begin Program" << endl;
  int a = 2;
  cout << "C, Before a = " << a << endl;
  
  int j = cfunction(&a);
  
  cout << "C, After j = " << j << endl;
  cout << "C, After a = " << a << endl;
  
  float b = 20.0;
  cout << "C++, Before b = " << b << endl;
  
  float k = cppfunction(&b);
  
  cout << "C++, After k = " << k << endl;
  cout << "C++, After b = " << b << endl;
  
  cout << "end Program" << endl;
  
  return 0;
}
