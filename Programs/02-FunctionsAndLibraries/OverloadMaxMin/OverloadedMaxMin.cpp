/*
 * File: OverloadedMaxMin.cpp
 * --------------------------
 * This file tests the overloaded versions of max.
 */

#include <iostream>
#include <string>
#include "maxmin.h"
using namespace std;

int main() {
   cout << "max('A', 'Z') = " << max('A', 'Z') << endl;
   cout << "max(3, 2) = " << max(3, 2) << endl;
   cout << "max(3L, 2L) = " << max(3L, 2L) << endl;
   cout << "max(3.1415926, 2.7182818) = " << max(3.1415926, 2.7182818) << endl;
   return 0;
}
