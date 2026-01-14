/*
 * File: DirectionTest.cpp
 * -----------------------
 * This file tests the Direction definition and functions as they
 * appear in the text.  To ensure that there is only a single
 * source for these code fragments, this test program uses the
 * shared copy of direction.h and direction.cpp files.
 */

#include <iostream>
#include "direction.h"
using namespace std;

int main() {
   for (Direction dir = NORTH; dir <= WEST; dir = Direction(dir + 1)) {
      cout << "leftFrom(" << directionToString(dir) << ") -> "
           << directionToString(leftFrom(dir)) << endl;
      cout << "rightFrom(" << directionToString(dir) << ") -> "
           << directionToString(rightFrom(dir)) << endl;
   }
   return 0;
}
