/*
 * File: PrecisionExercise.cpp
 * ---------------------------
 * This program generates the sample run for the exercise on precision
 * specification.
 */

#include <iostream>
#include <iomanip>
using namespace std;

/* Constants */

const double PI = 3.14159265358979323846;

int main() {
   cout << fixed << setprecision(15) << PI << endl;
   cout << fixed << setprecision(6) << PI << endl;
   cout << scientific << setprecision(15) << PI << endl;
   cout << uppercase << scientific << setprecision(6) << PI << endl;
   cout << fixed << setw(16) << setprecision(9) << PI << endl;
   cout << fixed << setfill('0') << setw(8) << setprecision(4) << PI << endl;
   return 0;
}
