/*
 * File: maxmin.h
 * --------------
 * This interface exports several versions of max and min that
 * preserve the type of their arguments.  Later in the course,
 * you will learn how to streamline this code further by using
 * templates for the same purpose.
 */

#ifndef _maxmin_h
#define _maxmin_h

/*
 * Function: max
 * Usage: larger = max(x, y);
 * --------------------------
 * Returns the larger of x and y.  This method is overloaded so
 * that it works with several numeric types.
 */

char max(char x, char y);
int max(int x, int y);
long max(long x, long y);
double max(double x, double y);

/*
 * Function: min
 * Usage: smaller = min(x, y);
 * ---------------------------
 * Returns the smaller of x and y.  This method is overloaded so
 * that it works with several numeric types.
 */

char min(char x, char y);
int min(int x, int y);
long min(long x, long y);
double min(double x, double y);

#endif
