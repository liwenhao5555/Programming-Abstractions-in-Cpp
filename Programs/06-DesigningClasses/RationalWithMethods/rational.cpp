/*
 * File: rational.cpp
 * ------------------
 * This file implements the Rational class.
 */

#include <string>
#include <cstdlib>
#include "rational.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

int gcd(int x, int y);

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * There are three constructors for the Rational class.  The default
 * constructor creates a Rational with a zero value, the one-argument
 * form converts an integer to a Rational, and the two-argument form
 * allows specifying a fraction.  The two argument form ensures that
 * the following invariants are maintained:
 *
 * 1. The fraction is always reduced to lowest terms.
 * 2. The denominator is always positive.
 * 3. The only representation of zero is 0/1.
 */

Rational::Rational() {
   num = 0;
   den = 1;
}

Rational::Rational(int n) {
   num = n;
   den = 1;
}

Rational::Rational(int x, int y) {
   if (x == 0) {
      num = 0;
      den = 1;
   } else {
      int g = gcd(abs(x), abs(y));
      num = x / g;
      den = abs(y) / g;
      if (y < 0) num = -num;
   }
}

Rational Rational::add(Rational r2) {
   return Rational(num * r2.den + r2.num * den, den * r2.den);
}

Rational Rational::subtract(Rational r2) {
   return Rational(num * r2.den - r2.num * den, den * r2.den);
}

Rational Rational::multiply(Rational r2) {
   return Rational(num * r2.num, den * r2.den);
}

Rational Rational::divide(Rational r2) {
   return Rational(num * r2.den, den * r2.num);
}

string Rational::toString() {
   if (den == 1) {
      return integerToString(num);
   } else {
      return integerToString(num) + "/" + integerToString(den);
   }
}

int gcd(int x, int y) {
   int r = x % y;
   while (r != 0) {
      x = y;
      y = r;
      r = x % y;
   }
   return y;
}

ostream & operator<<(ostream & os, Rational rat) {
   os << rat.toString();
   return os;
}
