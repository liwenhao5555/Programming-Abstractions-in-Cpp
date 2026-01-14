/*
 * File: ShowFileContents.cpp
 * --------------------------
 * This program displays the contents of a file chosen by the user.
 */

#include <iostream>
#include <fstream>
using namespace std;

/* Function prototypes */

void copyStream(istream & is, ostream & os);
string promptUserForFile(ifstream & infile, string prompt = "");

/* Main program */

int main() {
   ifstream infile;
   promptUserForFile(infile, "Input file: ");
   copyStream(infile, cout);
   infile.close();
   return 0;
}

# include "copyStream-code.h"

# include "promptUserForFile-input.h"
