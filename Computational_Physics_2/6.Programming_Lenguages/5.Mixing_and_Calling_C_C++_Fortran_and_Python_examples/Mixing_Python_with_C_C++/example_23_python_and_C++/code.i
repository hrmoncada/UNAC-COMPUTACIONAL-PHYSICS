%module code
%{
#include "code.h"
%}
%include "std_vector.i"
namespace std {

  /* On a side note, the names VecDouble and VecVecdouble can be changed, but the order of first the inner vector matters! */
  %template(VecDouble) vector<double>;
  %template(VecVecdouble) vector< vector<double> >;
}

%include "code.h"
