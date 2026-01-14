/*
 * File: CopyFile.cpp
 * ------------------
 * This program creates a copy of an input file.
 */

#include <iostream>
#include <fstream>
using namespace std;

/* Function prototypes */

void copyStream(istream & is, ostream & os);
string promptUserForFile(ifstream & infile, string prompt = "");
string promptUserForFile(ofstream & outfile, string prompt = "");

/* Main program */

int main() {
   ifstream infile;
   ofstream outfile;
   promptUserForFile(infile, "Input file:  ");
   promptUserForFile(outfile, "Output file: ");
   copyStream(infile, outfile);
   infile.close();
   outfile.close();
   return 0;
}

# include "copyStream-code.h"

# include "promptUserForFile-input.h"

# include "promptUserForFile-output.h"
