/*https://isocpp.org/wiki/faq/mixing-c-and-cpp
 This is C++ code */

#include <iostream> // std::cout, std::endl
using namespace std;

#include "Fred.h"

int main() {
  cout << "Begin Program" << endl; 
  
  Fred fred; // class struct
  c_function(&fred);
  
  cout << "End Program" << endl;
  
  return 0;
}
