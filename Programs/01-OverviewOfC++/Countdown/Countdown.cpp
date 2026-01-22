/*
 * File: Countdown.cpp
 * -------------------
 * This program counts backwards from the value START to zero.
 */

#include <iostream>
using namespace std;

/* Constant to specify the start of the countdown */

const int START = 10;

/* Main program */

int main() {
   for (int t = START; t >= 0; t--) {
      cout << t << endl;
   }
   return 0;
}
