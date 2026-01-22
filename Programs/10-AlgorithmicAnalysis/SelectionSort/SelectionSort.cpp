/*
 * File: SelectionSort.cpp
 * -----------------------
 * This file implements the selection sort algorithm.
 */

#include <iostream>
#include "vector.h"
using namespace std;

/* Function prototypes */

void sort(Vector<int> & vec);
void printVector(Vector<int> & vec);

/* Main program */

int main() {
   Vector<int> vec;
   vec += 56, 25, 37, 58, 95, 19, 73, 30;
   sort(vec);
   printVector(vec);
   return 0;
}

/*
 * Implementation notes: sort
 * --------------------------
 * This implementation uses an algorithm called selection sort, which can
 * be described as follows.  With your left hand (lh), point at each element
 * in the vector in turn, starting at index 0.  At each step in the cycle:
 *
 * 1. Find the smallest element in the range between your left hand and the
 *    end of the vector, and point at that element with your right hand (rh).
 *
 * 2. Move that element into its correct position by exchanging the elements
 *    indicated by your left and right hands.
 */

void sort(Vector<int> & vec) {
   int n = vec.size();
   for (int lh = 0; lh < n; lh++) {
      int rh = lh;
      for (int i = lh + 1; i < n; i++) {
         if (vec[i] < vec[rh]) rh = i;
      }
      int tmp = vec[lh];
      vec[lh] = vec[rh];
      vec[rh] = tmp;
   }
}

# include "printVector-int-code.h"
