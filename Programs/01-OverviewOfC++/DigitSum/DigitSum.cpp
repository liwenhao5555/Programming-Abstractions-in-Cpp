/*
 * File: DigitSum.cpp
 * ------------------
 * This program adds the digits in a number.
 */

#include <iostream>
using namespace std;

/* Function prototypes */

int digitSum(int n);

/* Main program */

int main() {
   cout << "Program to test the digitSum function." << endl;
   while (true) {
      int n;
      cout << "Enter a number (use -1 to stop): ";
      cin >> n;
      if (n < 0) break;
      cout << "digitSum(" << n << ") = " << digitSum(n) << endl;
   }
   return 0;
}

/*
 * Function: digitSum
 * ------------------
 * Returns the sum of the digits in the number n.
 */

int digitSum(int n) {
   int sum = 0;
   while (n > 0) {
      sum += n % 10;
      n /= 10;
   }
   return sum;
}
