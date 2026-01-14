/*
 * File: FlipCoin.cpp
 * ------------------
 * Simulates flipping a coin, counting the number of heads and tails.
 */

#include <iostream>
#include "random.h"
using namespace std;

/* Constants */

const int N_FLIPS = 100;

/* Function prototypes */

string flipCoin();

/* Main program */

int main() {
   int nHeads = 0;
   for (int i = 0; i < N_FLIPS; i++) {
      string flip = flipCoin();
      if (flip == "heads") nHeads++;
   }
   int nTails = N_FLIPS - nHeads;
   cout << "There were " << nHeads << " heads and "
                         << nTails << " tails." << endl;
   return 0;
}

/*
 * Function: flipCoin
 * Usage: string flip = flipCoin();
 * --------------------------------
 * Simulates a coin flip by returning the string "heads" or "tails" with
 * equal probability.
 */

string flipCoin() {
   if (randomChance(0.50)) {
      return "heads";
   } else {
      return "tails";
   }
}
