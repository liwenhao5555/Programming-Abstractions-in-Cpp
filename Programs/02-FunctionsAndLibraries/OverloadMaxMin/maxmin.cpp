/*
 * File: maxmin.cpp
 * ----------------
 * This file implements the various versions of the max and min functions.
 */

#include <iostream>
#include <string>
#include "maxmin.h"
using namespace std;

const bool TRACE = true;

char max(char x, char y) {
   if (TRACE) cout << "Calling char max" << endl;
   return (x > y) ? x : y;
}

int max(int x, int y) {
   if (TRACE) cout << "Calling int max" << endl;
   return (x > y) ? x : y;
}

long max(long x, long y) {
   if (TRACE) cout << "Calling long max" << endl;
   return (x > y) ? x : y;
}

double max(double x, double y) {
   if (TRACE) cout << "Calling double max" << endl;
   return (x > y) ? x : y;
}

long double max(long double x, long double y) {
   if (TRACE) cout << "Calling long double max" << endl;
   return (x > y) ? x : y;
}

char min(char x, char y) {
   if (TRACE) cout << "Calling char min" << endl;
   return (x < y) ? x : y;
}

int min(int x, int y) {
   if (TRACE) cout << "Calling int min" << endl;
   return (x < y) ? x : y;
}

long min(long x, long y) {
   if (TRACE) cout << "Calling long min" << endl;
   return (x < y) ? x : y;
}

double min(double x, double y) {
   if (TRACE) cout << "Calling double min" << endl;
   return (x < y) ? x : y;
}

long double min(long double x, long double y) {
   if (TRACE) cout << "Calling long double min" << endl;
   return (x < y) ? x : y;
}
