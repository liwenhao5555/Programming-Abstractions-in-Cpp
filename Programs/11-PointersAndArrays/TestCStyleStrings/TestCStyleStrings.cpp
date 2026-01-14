/*
 * File: CStyleStrings.cpp
 * -----------------------
 * This program tests several of the functions used with C-style
 * strings.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   char charArray[] = "hello, world";
   char *charPointer = (char *) "hello, world";
   cout << "charArray = 0x" << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charArray) << endl;
   cout << "&charArray[0] = 0x" << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charArray[0]) << endl;
   cout << "&charPointer = 0x" << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charPointer) << endl;
   cout << "&charPointer[0] = 0x" << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charPointer[0]) << endl;
   return 0;
}
