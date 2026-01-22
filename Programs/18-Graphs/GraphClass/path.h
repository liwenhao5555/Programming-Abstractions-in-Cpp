/*
 * File: path.h
 * ------------
 * This file is the interface for a Path class, which is conceptually
 * a vector of arcs.
 */

#ifndef _path_h
#define _path_h

#include <string>

#include "graphtypes.h"
#include "vector.h"
class Path {

public:

/*
 * Constructor: Path
 * Usage: Path path;
 * -----------------
 * Constructs an empty path object;
 */

   Path();

/*
 * Method: size
 * Usage: nCities = path.size();
 * -----------------------------
 * Returns the number of nodes in this path.
 */

   int size();

/*
 * Method: isEmpty
 * Usage: if (path.isEmpty()) . . .
 * --------------------------------
 * Returns true if the path is empty.
 */

   bool isEmpty();

/*
 * Method: clear
 * Usage: path.clear();
 * --------------------
 * Removes all arcs from the path.
 */

   void clear();

/*
 * Method: operator[]
 * Usage: arc = path[index];
 * -------------------------
 * Returns the arc at the specified index position of the path.
 * Selecting an arc outside of the range raises an Error.
 */

   Arc *operator[](int index);

/*
 * Method: getStart
 * Usage: node = path.getStart();
 * ------------------------------
 * Returns the first node in the path.  This method returns
 * NULL if the path is empty.
 */

   Node *getStart();

/*
 * Method: getFinish
 * Usage: node = path.getFinish();
 * -------------------------------
 * Returns the last node in the path.  This method returns
 * NULL if the path is empty.
 */

   Node *getFinish();

/*
 * Method: extend
 * Usage: path.extend(arc);
 * ------------------------
 * Extends the path by adding a new node at the end, updating the
 * total cost of the path.
 */

   void extend(Arc *arc);

/*
 * Method: retract
 * Usage: path.retract();
 * ----------------------
 * Shortens the path by removing the last arc.
 */

   void retract();

/*
 * Method: getTotalCost
 * Usage: path.getTotalCost();
 * ---------------------------
 * Returns the total cost of this path.
 */

   double getTotalCost();

/*
 * Method: toString
 * Usage: str = path.toString();
 * -----------------------------
 * Returns a string showing the nodes in the path.
 */

   std::string toString();

private:

   Vector<Arc *> arcs;
   double totalCost;

};

#endif
