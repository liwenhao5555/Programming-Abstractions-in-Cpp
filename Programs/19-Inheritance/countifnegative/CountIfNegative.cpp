/*
 * File: CountIfNegative.cpp
 * -------------------------
 * This program counts the number of negative values in a vector.
 */

#include <iostream>
#include <algorithm>
#include "vector.h"
using namespace std;

/* Main program */

int main() {
   Vector<int> v;
   v += 1, 3, -20, 4, 45, 11, -16, 100;
   int neg = count_if(v.begin(), v.end(), bind2nd(less<int>(), 0));
   cout << v << " has " << neg << " negative values." << endl;
}
