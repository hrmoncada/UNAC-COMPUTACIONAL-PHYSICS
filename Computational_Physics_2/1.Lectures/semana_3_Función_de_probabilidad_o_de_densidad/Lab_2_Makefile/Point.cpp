/*
 *          File: Point.cpp
 * Last Modified: February 19, 2000
 *         Topic: Writing Make Files
 * ----------------------------------------------------------------
 */

#include "Point.h"

Point::Point()
{
  x = 0;
  y = 0;
}

Point::Point(int xval, int yval)
{
  x = xval;
  y = yval;
}

void Point::move(int dx, int dy)
{
  x += dx;
  y += dy;
}

int Point::get_x() const
{
  return x;
}

int Point::get_y() const
{
  return y;
}
