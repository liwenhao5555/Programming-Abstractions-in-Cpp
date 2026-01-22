/*
 * File: PointTest.cpp
 * -------------------
 * This file creates and displays some points to test the
 * implementation of the Point class.  In this version, the
 * Point class is defined as a standalone unit rather than as
 * a separate class with an interface.
 */

#include <iostream>

/*
 * Class: Point
 * ------------
 * This class represents an x-y coordinate point on a two-dimensional
 * integer grid.
 */

#include <string>
#include "strlib.h"
using namespace std;

class Point {

public:

   Point() {
      x = 0;
      y = 0;
   }

   Point(int xc, int yc) {
      x = xc;
      y = yc;
   }

   int getX() {
      return x;
   }

   int getY() {
      return y;
   }

   string toString() {
      return "(" + integerToString(x) + ","
                 + integerToString(y) + ")";
   }

private:
   int x;
   int y;

};

int main() {
   Point origin(0, 0);
   Point pt(3, 4);
   cout << "origin = " << origin.toString() << endl;
   cout << "pt = " << pt.toString() << endl;
   return 0;
}
