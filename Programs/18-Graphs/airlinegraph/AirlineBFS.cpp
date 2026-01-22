/*
 * File: AirlineDFS.cpp
 * --------------------
 * This program performs a depth-first search on the airline graph
 * as it appears in Figure 18-2.
 */

#include <iostream>
#include <string>
#include "graphtypes.h"
#include "queue.h"
#include "set.h"
#include "simpio.h"
using namespace std;

/* Function prototypes */

void breadthFirstSearch(Node *node);
void visit(Node *node);
void initAirlineGraph(SimpleGraph & airline);
void addFlight(SimpleGraph & airline, string c1, string c2, int miles);
void addNode(SimpleGraph & g, string name);
void addArc(SimpleGraph & g, Node *n1, Node *n2, double cost);

/* Main program */

int main() {
   SimpleGraph airline;
   initAirlineGraph(airline);
   string name = getLine("Starting city: ");
   breadthFirstSearch(airline.nodeMap[name]);
   return 0;
}

/*
 * Function: breadthFirstSearch
 * Usage: breadthFirstSearch(node);
 * --------------------------------
 * Initiates a breadth-first search beginning at the specified node.
 */

void breadthFirstSearch(Node *node) {
   Set<Node *> visited;
   Queue<Node *> queue;
   queue.enqueue(node);
   while (!queue.isEmpty()) {
      node = queue.dequeue();
      if (!visited.contains(node)) {
         visit(node);
         visited.add(node);
         foreach (Arc *arc in node->arcs) {
            queue.enqueue(arc->finish);
         }
      }
   }
}

/*
 * Function: visit
 * Usage: visit(node);
 * -------------------
 * Prints out the name of the specified node to show that it has
 * been visited.  This function is a placeholder for a presumably
 * more complex function that performs whatever operations are
 * required by a particular application.
 */

void visit(Node *node) {
   cout << node->name << endl;
}

# include "AirlineGraph.inc"
