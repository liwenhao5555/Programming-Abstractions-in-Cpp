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
   GRect *rect = new GRect(cx - 100, cy - 50, 200, 100);
   GOval *oval = new GOval(cx - 100, cy - 50, 200, 100);
   oval->setFilled(true);
   oval->setColor("GREEN");
   rect->draw(gw);
   oval->draw(gw);
   delete rect;
   delete oval;
   return 0;
}
