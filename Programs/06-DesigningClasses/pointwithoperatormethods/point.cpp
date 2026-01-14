/*
 * File: point.cpp
 * ---------------
 * This file implements the point.h interface.
 */

#include <string>
#include "point.h"
#include "strlib.h"
using namespace std;

Point::Point() {
   x = 0;
   y = 0;
}

Point::Point(int xc, int yc) {
   x = xc;
   y = yc;
}

int Point::getX() {
   return x;
}

int Point::getY() {
   return y;
}

string Point::toString() {
   return "(" + integerToString(x) + "," + integerToString(y) + ")";
}

bool Point::operator==(Point p2) {
   return x == p2.x && y == p2.y;
}

bool Point::operator!=(Point p2) {
   return x != p2.x || y != p2.y;
}

ostream & operator<<(ostream & os, Point pt) {
   os << pt.toString();
   return os;
}
