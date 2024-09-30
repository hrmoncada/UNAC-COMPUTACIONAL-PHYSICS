/*
 *          File: main.cpp
 * Last Modified: February 19, 2000
 *         Topic: Writing Make Files
 * ----------------------------------------------------------------
 */

#include <iostream>
#include "Point.h"
#include "Rectangle.h"

using namespace std;

int main() {
  int x, y;

  cout << "Please enter x and y value for point p1: ";
  cin >> x >> y;

  Point p1(x, y);

  p1.move(3, 5);
  cout << "\nMoved p1 by 3, 5--p1 now at "
       << p1.get_x() << ", " << p1.get_y() << endl;

  cout << "\nWe'll use p1 point for the bottom left point of" << endl
       << "rectangle r1, please enter the x and y value for" << endl
       << "top right point: ";
  cin >> x >> y;

  Point p2(x, y);
  Rectangle r1(p1, p2);
  cout << "\nRectangle r1 area is: " << r1.area() << endl;

  return 0;
}
