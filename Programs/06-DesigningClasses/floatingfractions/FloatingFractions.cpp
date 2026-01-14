/*
 * File: FloatingFractions.cpp
 * ---------------------------
 * This file illustrates the problem of roundoff error with
 * doubles.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   double a = 1.0 / 2.0;
   double b = 1.0 / 3.0;
   double c = 1.0 / 6.0;
   double sum = a + b + c;
   cout << "1/2 + 1/3 + 1/6 = " << setprecision(16) << sum << endl;
   return 0;
}
