#include <vector>
#include "code.h"

using namespace std;

vector<double> average (vector< vector<double> > i_matrix) {

  // Compute average of each row..
  vector <double> averages;
  for (int r = 0; r < i_matrix.size(); r++){
    double rsum = 0.0;
    double ncols= i_matrix[r].size();
    for (int c = 0; c< i_matrix[r].size(); c++){
      rsum += i_matrix[r][c];
    }
    averages.push_back(rsum/ncols);
  }
  return averages;
}
