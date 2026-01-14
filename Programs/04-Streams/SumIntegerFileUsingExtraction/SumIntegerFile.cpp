/*
 * File: SumIntegerFile.cpp
 * ------------------------
 * This program calculates and prints the sum of the integers in
 * a data file chosen by the user.  This version of the program
 * makes no attempt to check that the file is formatted correctly
 * and is therefore not appropriate for use in practice.  It does,
 * however, illustrate the use of the extraction operator with files.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "error.h"
using namespace std;

/* Function prototypes */

string promptUserForFile(ifstream & infile, string prompt = "");

/* Main program */

int main() {
   ifstream infile;
   promptUserForFile(infile, "Input file: ");
   int total = 0;
   int value;
   while (infile >> value) {
      total += value;
   }
   infile.close();
   cout << "The sum is " << total << endl;
   return 0;
}

# include "promptUserForFile-input.h"
