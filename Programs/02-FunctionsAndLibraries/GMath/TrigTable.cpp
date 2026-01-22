/*
 * File: TrigTable.cpp
 * -------------------
 * This program uses the gmath.h interface to construct a table of
 * sines and cosines for angles in degrees.
 */

#include <iostream>
#include <iomanip>
#include "gmath.h"
using namespace std;

int main() {
   cout << " x   sin(x)   cos(x)" << endl;
   cout << "---+--------+--------" << endl;
   for (int theta = 0; theta <= 90; theta++) {
      cout << setw(2) << theta << "   ";
      cout << setfill('0') << fixed;
      cout << setw(6) << setprecision(4) << sinDegrees(theta) << "   ";
      cout << setw(6) << setprecision(4) << cosDegrees(theta) << endl;
   }
   return 0;
}
