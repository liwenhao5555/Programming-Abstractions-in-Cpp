/*
 * File: GraphTest.cpp
 * -------------------
 * This program implements several algorithms for graphs.
 */

#include <iostream>
#include <fstream>
#include "cmdscan.h"
#include "filelib.h"
#include "graphio.h"
#include "graphtypes.h"
#include "queue.h"
#include "set.h"
#include "strlib.h"
#include "tokenscanner.h"
using namespace std;

/* Function prototypes */

void initCommandScanner(CommandScanner & cs);
void runBFSCommand(TokenScanner & scanner, void *clientData);
void runDFSCommand(TokenScanner & scanner, void *clientData);
void runListCommand(TokenScanner & scanner, void *clientData);
void runLoadCommand(TokenScanner & scanner, void *clientData);
void runSaveCommand(TokenScanner & scanner, void *clientData);
Node *scanNode(TokenScanner & scanner, SimpleGraph & g);
void breadthFirstSearch(Node *node);
void depthFirstSearch(Node *node);
void visitUsingDFS(Node *node, Set<Node *> & visited);
void visit(Node *node);
void listNode(Node *node);

/* Main program */

int main() {
   SimpleGraph *graph = new SimpleGraph;
   CommandScanner cs(graph);
   initCommandScanner(cs);
   cs.run();
   return 0;
}

/* Commands */

void initCommandScanner(CommandScanner & cs) {
   cs.define("bfs", runBFSCommand,
             "bfs <node> -- Performs a breadth-first search from node");
   cs.define("dfs", runDFSCommand,
             "dfs <node> -- Performs a depth-first search from node");
   cs.define("list", runListCommand,
             "list -- Lists the nodes and connections");
   cs.define("load", runLoadCommand,
             "load \"file\" -- Loads a file of nodes and arcs");
   cs.define("save", runSaveCommand,
             "save \"file\" -- Saves a file of nodes and arcs");
}

void runBFSCommand(TokenScanner & scanner, void *clientData) {
   SimpleGraph *gp = (SimpleGraph *) clientData;
   Node *n1 = scanNode(scanner, *gp);
   breadthFirstSearch(n1);
}

void runDFSCommand(TokenScanner & scanner, void *clientData) {
   SimpleGraph *gp = (SimpleGraph *) clientData;
   Node *node = scanNode(scanner, *gp);
   depthFirstSearch(node);
}

void runListCommand(TokenScanner & scanner, void *clientData) {
   SimpleGraph *gp = (SimpleGraph *) clientData;
   foreach (Node *node in gp->nodes) {
      listNode(node);
   }
}

void runLoadCommand(TokenScanner & scanner, void *clientData) {
   SimpleGraph *gp = (SimpleGraph *) clientData;
   string filename = scanner.nextToken();
   if (filename == "") error("Missing file name in load command");
   if (filename[0] == '"') {
      filename = filename.substr(1, filename.length() - 2);
   } else {
      filename += ".txt";
   }
   ifstream infile;
   openFile(infile, filename);
   if (infile.fail()) error("Can't open " + filename);
   readGraph(*gp, infile);
   infile.close();
}

void runSaveCommand(TokenScanner & scanner, void *clientData) {
   SimpleGraph *gp = (SimpleGraph *) clientData;
   string filename = scanner.nextToken();
   if (filename == "") error("Missing file name in save command");
   if (filename[0] == '"') {
      filename = filename.substr(1, filename.length() - 2);
   } else {
      filename += ".txt";
   }
   ofstream outfile;
   openFile(outfile, filename);
   if (outfile.fail()) error("Can't open " + filename);
   writeGraph(*gp, outfile);
   outfile.close();
}

/*
 * Function: breadthFirstSearch
 * Usage: breadthFirstSearch(start);
 * ---------------------------------
 * Calls visit(node) for every node in a breadth-first search expansion
 * from the start node.  The breadth-first algorithm visits nodes in
 * order by their distance in hops from the start node.
 */

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
 * Function: depthFirstSearch
 * Usage: depthFirstSearch(start);
 * -------------------------------
 * Calls visit(node) for every node in a depth-first search expansion
 * from the start node.  The depth-first algorithm explores the graph
 * recursively, choosing each arc from the start node and visiting
 * every node reachable along that path before moving on to the next arc.
 */

void depthFirstSearch(Node *node) {
   Set<Node *> visited;
   visitUsingDFS(node, visited);
}

/*
 * Function: visitUsingDFS
 * Usage: visitUsingDFS(node, visited);
 * ------------------------------------
 * Executes a depth-first search beginning at the specified node that
 * avoids revisiting any nodes in the visited set.
 */

void visitUsingDFS(Node *node, Set<Node *> & visited) {
   if (visited.contains(node)) return;
   visit(node);
   visited.add(node);
   foreach (Arc *arc in node->arcs) {
      visitUsingDFS(arc->finish, visited);
   }
}

/* Helper functions */

Node *scanNode(TokenScanner & scanner, SimpleGraph & g) {
   string name = scanner.nextToken();
   if (name[0] == '"') name = name.substr(1, name.length() - 2);
   return g.nodeMap.get(name);
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
   cout << "Visiting node " << node->name << endl;
}

void listNode(Node *node) {
   cout << node->name << " connects to:" << endl;
   foreach (Arc *arc in node->arcs) {
      Node *n2 = arc->finish;
      double cost = arc->cost;
      cout << "  " << n2->name << " (" << cost << ")" << endl;
   }
}
