/*
 * File: TestDirection.cpp
 * -----------------------
 * This file tests the Direction enumerated type.
 */

using namespace std;
#include <iostream>

#include "direction.h"
int main() {
   cout << "leftFrom(NORTH) = " << leftFrom(NORTH) << endl;
   cout << "leftFrom(EAST) = " << leftFrom(EAST) << endl;
   cout << "leftFrom(SOUTH) = " << leftFrom(SOUTH) << endl;
   cout << "leftFrom(WEST) = " << leftFrom(WEST) << endl;
   cout << "rightFrom(NORTH) = " << rightFrom(NORTH) << endl;
   cout << "rightFrom(EAST) = " << rightFrom(EAST) << endl;
   cout << "rightFrom(SOUTH) = " << rightFrom(SOUTH) << endl;
   cout << "rightFrom(WEST) = " << rightFrom(WEST) << endl;
   return 0;
}
