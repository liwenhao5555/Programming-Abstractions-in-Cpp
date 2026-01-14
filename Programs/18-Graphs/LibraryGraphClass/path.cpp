/*
 * File: path.cpp
 * --------------
 * This file implements the Path class.
 */

#include "error.h"
#include "path.h"
#include "vector.h"

Path::Path() {
   totalCost = 0;
}

int Path::size() {
   return arcs.size();
}

bool Path::isEmpty() {
   return arcs.isEmpty();
}

void Path::clear() {
   arcs.clear();
   totalCost = 0;
}

Arc *Path::operator[](int index) {
   return arcs[index];
}

Node *Path::getStart() {
   if (isEmpty()) return NULL;
   return arcs[0]->finish;
}

Node *Path::getFinish() {
   if (isEmpty()) return NULL;
   return arcs[arcs.size() - 1]->finish;
}

void Path::extend(Arc *arc) {
   if (!isEmpty() && getFinish() != arc->start) {
      error("extend: arc doesn't start at the end of the path");
   }
   arcs.add(arc);
   totalCost += arc->cost;
}

void Path::retract() {
   if (isEmpty()) error("retract: path is empty");
   totalCost -= arcs[arcs.size() - 1]->cost;
   arcs.remove(arcs.size() - 1);
}

double Path::getTotalCost() {
   return totalCost;
}

string Path::toString() {
   if (isEmpty()) return "";
   string str = arcs[0]->start->name;
   for (int i = 0; i < arcs.size(); i++) {
      str += " -> " + arcs[i]->finish->name;
   }
   return str;
}
