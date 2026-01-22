/*
 * File: CircleArea.cpp
 * --------------------
 * This program calculates the area of a circle using a function
 * definition for the area calculation.
 */

#include <iostream>
using namespace std;

/* Constants */

const double PI = 3.14159265358979323846;

/* Function prototypes */

double circleArea(double r);

/* Main program */

int main() {
   double r;
   cout << "Enter radius: ";
   cin >> r;
   double area = circleArea(r);
   cout << "The area of a circle of radius " << r << " is " << area << endl;
   return 0;
}

/*
 * Function: circleArea
 * Usage: double area = circleArea(r);
 * -----------------------------------
 * Returns the area of a circle of radius r.
 */

double circleArea(double r) {
   return PI * r * r;
}
