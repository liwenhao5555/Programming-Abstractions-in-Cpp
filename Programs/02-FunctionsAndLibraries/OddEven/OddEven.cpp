/*
 * File: OddEven.cpp
 * -----------------
 * This program determines whether a number is odd or even.
 */

#include <iostream>
using namespace std;

int main() {
   int n;
   cout << "Enter a number: ";
   cin >> n;
   if (n % 2 == 0) {
      cout << "That number is even." << endl;
   } else {
      cout << "That number is odd." << endl;
   }
   return 0;
}
