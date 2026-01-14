/*
 * File: PointTest.cpp
 * -------------------
 * This file creates and displays some points to test the
 * implementation of the Point class.
 */

#include <iostream>
#include <math.h>
#include "point.h"
using namespace std;

double distanceBetween(Point p1, Point p2);

int main() {
   Point origin(0, 0);
   Point endpoint(3, 4);
   cout << "The distance from " << origin.toString()
        << " to " << endpoint.toString()
        << " is " << distanceBetween(origin, endpoint) << endl;
   return 0;
}

double distanceBetween(Point p1, Point p2) {
   double dx = p2.getX() - p1.getX();
   double dy = p2.getY() - p1.getY();
   return sqrt(dx * dx + dy * dy);
}
