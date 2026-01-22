/*
 * File: TestGObjects.cpp
 * ----------------------
 * Simple test program for the GObject classes.
 */

#include <iostream>
#include "gwindow.h"
#include "gobjects.h"
using namespace std;

int main() {
   GWindow gw(600, 450);
   double cx = gw.getWidth() / 2;
   double cy = gw.getHeight() / 2;
   GCircle circle(cx, cy, cy);
   circle.setColor("MAGENTA");
   GRect rect(cx - 100, cy - 50, 200, 100);
   GOval oval(cx - 100, cy - 50, 200, 100);
   oval.setColor("GREEN");
   circle.draw(gw);
   rect.draw(gw);
   oval.draw(gw);
   return 0;
}

