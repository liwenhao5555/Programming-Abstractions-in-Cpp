/*
 * File: ExtractWords.cpp
 * ----------------------
 * This program defines and tests the function extractWords, which
 * extracts all consecutive sequences of letters from a string and
 * stores them in a Vector<string>.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "vector.h"
using namespace std;

/* Function prototypes */

void extractWords(string str, Vector<string> & words);

/* Main program */

int main() {
   cout << "This program tests the extractWords function." << endl;
   while (true) {
      string line;
      cout << "Enter a line of text: ";
      getline(cin, line);
      if (line == "") break;
      Vector<string> words;
      extractWords(line, words);
      cout << "The words in that line are:" << endl;
      for (int i = 0; i < words.size(); i++) {
         cout << "  \"" << words[i] << "\"" << endl;
      }
   }
   return 0;
}

# include "extractWords-code.h"
