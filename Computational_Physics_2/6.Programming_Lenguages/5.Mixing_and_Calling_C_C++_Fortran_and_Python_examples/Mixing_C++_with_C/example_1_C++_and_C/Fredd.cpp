// This is C++ code
#include "Fred.h"

Fred::Fred() : a_(0) { }

void Fred::wilma(int a) { }

Fred* cplusplus_callback_function(Fred* fred) {
  int a = 123;  
  fred->wilma(a);
  return fred;
}
