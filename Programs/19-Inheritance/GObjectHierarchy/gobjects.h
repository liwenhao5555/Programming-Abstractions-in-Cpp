/*
 * File: gobjects.h
 * ----------------
 * This file defines a simple hierarchy of graphical objects.
 */

#ifndef _gobjects_h
#define _gobjects_h

#include <string>
#include "conflicts.h"
#include "gwindow.h"

/*
 * Class: GObject
 * --------------
 * This class is the root of the hierarchy and encompasses all objects
 * that can be displayed in a window.  Clients typically use a pointer
 * to a GObject rather than the GObject itself.
 */

class GObject {

public:

/*
 * Method: setLocation
 * Usage: gobj->setLocation(x, y);
 * -------------------------------
 * Sets the x and y coordinates of gobj to the specified values.
 */

   void setLocation(double x, double y);

/*
 * Method: move
 * Usage: gobj->move(dx, dy);
 * --------------------------
 * Adds dx and dy to the coordinates of gobj.
 */

   void move(double x, double y);

/*
 * Method: setColor
 * Usage: gobj->setColor(color);
 * -----------------------------
 * Sets the color of gobj.
 */

   void setColor(std::string color);

/*
 * Abstract method: draw
 * Usage: gobj->draw(gw);
 * ----------------------
 * Draws the graphical object on the GraphicsWindow specified by gw.
 * This method is implemented by the specific GObject subclasses.
 */

   virtual void draw(GWindow & gw) = 0;

protected:

/* The following methods and fields are available to the subclasses */

   GObject();                        /* Superclass constructor         */
   std::string color;                /* The color of the object        */
   double x, y;                      /* The coordinates of the object  */

};

/*
 * Subclass: GLine
 * ---------------
 * The GLine subclass represents a line segment on the window.
 */

class GLine : public GObject {

public:

/*
 * Constructor: GLine
 * Usage: GLine *lp = new GLine(x1, y1, x2, y2);
 * ---------------------------------------------
 * Creates a line segment that extends from (x1, y1) to (x2, y2).
 */

   GLine(double x1, double y1, double x2, double y2);

/* Prototypes for the overridden virtual methods */

   virtual void draw(GWindow & gw);

private:
   double dx;                      /* Horizontal distance from x1 to x2    */
   double dy;                      /* Vertical distance from y1 to y2      */

};

/*
 * Subclass: GRect
 * ---------------
 * The GRect subclass represents a rectangle.
 */

class GRect : public GObject {

public:

/*
 * Constructor: GRect
 * Usage: GRect *rp = new GRect(x, y, width, height);
 * --------------------------------------------------
 * Creates a rectangle of the specified size whose upper left corner is (x, y).
 */

   GRect(double x, double y, double width, double height);

/*
 * Method: setFilled
 * Usage: rp->setFilled(flag);
 * ---------------------------
 * Indicates whether the rectangle is filled.
 */

   void setFilled(bool flag);

/* Prototypes for the overridden virtual methods */

   virtual void draw(GWindow & gw);

private:
   double width, height;           /* Dimensions of the rectangle          */
   bool filled;                    /* True if the rectangle is filled      */

};

/*
 * Subclass: GOval
 * ---------------
 * The GOval subclass represents an oval defined by a bounding rectangle.
 */

class GOval : public GObject {

public:

/*
 * Constructor: GOval
 * Usage: GOval *op = new GOval(x, y, width, height);
 * --------------------------------------------------
 * Creates an oval inscribed in the specified rectangle.
 */

   GOval(double x, double y, double width, double height);

/*
 * Method: setFilled
 * Usage: op->setFilled(flag);
 * ---------------------------
 * Indicates whether the oval is filled.
 */

   void setFilled(bool flag);

/* Prototypes for the overridden virtual methods */

   virtual void draw(GWindow & gw);

private:
   double width, height;           /* Dimensions of the bounding rectangle */
   bool filled;                    /* True if the oval is filled           */

};

#endif
