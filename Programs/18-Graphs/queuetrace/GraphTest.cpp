/*
 * File: GraphTest.cpp
 * -------------------
 * This program implements several algorithms for graphs.
 */

#include <iostream>
#include <fstream>
#include "cmdscan.h"
#include "graph.h"
#include "graphtypes.h"
#include "path.h"
#include "pqueue.h"
#include "queue.h"
#include "set.h"
#include "strlib.h"
#include "tokenscanner.h"
#include "vector.h"
using namespace std;

/* Function prototypes */

void initCommandScanner(CommandScanner & cs);
void runBFSCommand(TokenScanner & scanner, void *clientData);
void runDFSCommand(TokenScanner & scanner, void *clientData);
void runClearCommand(TokenScanner & scanner, void *clientData);
void runConnectCommand(TokenScanner & scanner, void *clientData);
void runDijkstraCommand(TokenScanner & scanner, void *clientData);
void runKruskalCommand(TokenScanner & scanner, void *clientData);
void runListCommand(TokenScanner & scanner, void *clientData);
void runLoadCommand(TokenScanner & scanner, void *clientData);
void runNodeCommand(TokenScanner & scanner, void *clientData);
void runPathExistsCommand(TokenScanner & scanner, void *clientData);

void breadthFirstSearch(Node *start, Node *finish, Set<Node *> & visited);
void depthFirstSearch(Node *start, Node *finish, Set<Node *> & visited);
bool pathExists1(Node *start, Node *finish, Set<Node *> & visited);
bool pathExists2(Node *start, Node *finish, Set<Node *> & visited);
Path findShortestPath(Node *start, Node *finish, bool trace);
void listQueue(PriorityQueue<Path> queue);
Graph<Node,Arc> findMinimumSpanningTree(Graph<Node,Arc> & g, bool trace);

void visit(Node *node);
void listNode(Node *node);
void loadGraphFile(ifstream & infile, Graph<Node,Arc> & g);
Node *scanNode(TokenScanner & scanner, Graph<Node,Arc> & g,
                                       bool create = false);
Arc *scanArc(TokenScanner & scanner, Graph<Node,Arc> & g,
                                      bool create = false);

/* Main program */

int main() {
   Graph<Node,Arc> graph;
   CommandScanner cs(&graph);
   initCommandScanner(cs);
   cs.run();
   return 0;
}

/* Commands */

void initCommandScanner(CommandScanner & cs) {
   cs.define("bfs", runBFSCommand,
             "bfs n1 -- Performs a breadth-first search from n1");
   cs.define("dfs", runDFSCommand,
             "dfs n1 -- Performs a depth-first search from n1");
   cs.define("clear", runClearCommand,
             "clear -- Deletes all nodes from the graph");
   cs.define("connect", runConnectCommand,
             "connect <n1>-<n2> [<cost>] -- Connects n1 and n2");
   cs.define("dijkstra", runDijkstraCommand,
             "dijkstra n1 n2 -- Dijkstra's algorithm to find shortest path");
   cs.define("kruskal", runKruskalCommand,
             "kruskal -- Kruskal's algorithm for minimum spanning tree");
   cs.define("list", runListCommand,
             "list -- Lists the nodes and connections");
   cs.define("load", runLoadCommand,
             "load \"file\" -- Loads a file of nodes and arcs");
   cs.define("node", runNodeCommand,
             "node <name> -- Adds a node");
   cs.define("pathExists", runPathExistsCommand,
             "pathExists n1 n2 -- Checks whether a path exists from n1 to n2");
}

void runBFSCommand(TokenScanner & scanner, void *clientData) {
   Graph<Node,Arc> *gp = (Graph<Node,Arc> *) clientData;
   Node *n1 = scanNode(scanner, *gp);
   Node *n2 = NULL;
   if (scanner.hasMoreTokens()) {
      n2 = scanNode(scanner, *gp);
   }
   Set<Node *> visited;
   breadthFirstSearch(n1, n2, visited);
}

void runClearCommand(TokenScanner & scanner, void *clientData) {
   Graph<Node,Arc> *gp = (Graph<Node,Arc> *) clientData;
   gp->clear();
}

void runConnectCommand(TokenScanner & scanner, void *clientData) {
   Graph<Node,Arc> *gp = (Graph<Node,Arc> *) clientData;
   scanArc(scanner, *gp);
}

void runDFSCommand(TokenScanner & scanner, void *clientData) {
   Graph<Node,Arc> *gp = (Graph<Node,Arc> *) clientData;
   Node *n1 = scanNode(scanner, *gp);
   Node *n2 = NULL;
   if (scanner.hasMoreTokens()) {
      n2 = scanNode(scanner, *gp);
   }
   Set<Node *> visited;
   depthFirstSearch(n1, n2, visited);
}

void runDijkstraCommand(TokenScanner & scanner, void *clientData) {
   Graph<Node,Arc> *gp = (Graph<Node,Arc> *) clientData;
   Node *n1 = scanNode(scanner, *gp);
   Node *n2 = scanNode(scanner, *gp);
   bool trace = scanner.nextToken() == "trace";
   Path path = findShortestPath(n1, n2, trace);
   double cost = path.getTotalCost();
   if (cost < 0) {
      cout << "No path exists" << endl;
   } else {
      cout << path.toString() << " (" << cost << ")" << endl;
   }
}

void runKruskalCommand(TokenScanner & scanner, void *clientData) {
   Graph<Node,Arc> *gp = (Graph<Node,Arc> *) clientData;
   bool trace = scanner.nextToken() == "trace";
   Graph<Node,Arc> mst = findMinimumSpanningTree(*gp, trace);
   foreach (Node *node in mst.getNodeSet()) {
      listNode(node);
   }
}

void runListCommand(TokenScanner & scanner, void *clientData) {
   Graph<Node,Arc> *gp = (Graph<Node,Arc> *) clientData;
   foreach (Node *node in gp->getNodeSet()) {
      listNode(node);
   }
}

void runLoadCommand(TokenScanner & scanner, void *clientData) {
   Graph<Node,Arc> *gp = (Graph<Node,Arc> *) clientData;
   string filename = scanner.nextToken();
   if (filename == "") error("Missing file name in load command");
   if (filename[0] == '"') {
      filename = filename.substr(1, filename.length() - 2);
   } else {
      filename += ".txt";
   }
   ifstream infile;
   infile.open(filename.c_str());
   if (infile.fail()) error("Can't open " + filename);
   loadGraphFile(infile, *gp);
   infile.close();
}

void runNodeCommand(TokenScanner & scanner, void *clientData) {
   Graph<Node,Arc> *gp = (Graph<Node,Arc> *) clientData;
   scanNode(scanner, *gp, true);
}

void runPathExistsCommand(TokenScanner & scanner, void *clientData) {
   Graph<Node,Arc> *gp = (Graph<Node,Arc> *) clientData;
   Node *n1 = scanNode(scanner, *gp);
   Node *n2 = scanNode(scanner, *gp);
   Set<Node *> v1, v2;
   if (pathExists1(n1, n2, v1) != pathExists2(n1, n2, v2)) {
      error("Two implementations of pathExists are inconsistent");
   }
   v1.clear();
   if (pathExists1(n1, n2, v1)) {
      cout << "A path exists";
   } else {
      cout << "No path exists";
   }
   cout << " between " << n1->name << " and " << n2->name << endl;
}

/* Algorithms */

void breadthFirstSearch(Node *start, Node *finish, Set<Node *> & visited) {
   Queue<Node *> queue;
   queue.enqueue(start);
   while (!queue.isEmpty()) {
      Node *node = queue.dequeue();
      if (node == finish) return;
      if (!visited.contains(node)) {
         visit(node);
         visited.add(node);
         foreach (Arc *arc in node->arcs) {
            queue.enqueue(arc->finish);
         }
      }
   }
}

void depthFirstSearch(Node *start, Node *finish, Set<Node *> & visited) {
   if (visited.contains(start)) return;
   visit(start);
   visited.add(start);
   if (start == finish) return;
   foreach (Arc *arc in start->arcs) {
      depthFirstSearch(arc->finish, finish, visited);
   }
}

#define pathExists pathExists1

bool pathExists(Node *start, Node *finish, Set<Node *> & visited) {
   if (start == finish) return true;
   if (visited.contains(start)) return false;
   visited.add(start);
   foreach (Arc *arc in start->arcs) {
      if (pathExists(arc->finish, finish, visited)) return true;
   }
   return false;
}

#undef pathExists
#define pathExists pathExists2

bool pathExists(Node *start, Node *finish, Set<Node *> & visited) {
   Queue<Node *> queue;
   queue.enqueue(start);
   while (!queue.isEmpty()) {
      Node *node = queue.dequeue();
      if (node == finish) return true;
      if (!visited.contains(node)) {
         visited.add(node);
         foreach (Arc *arc in node->arcs) {
            queue.enqueue(arc->finish);
         }
      }
   }
   return false;
}

#undef pathExists
#define pathExists pathExists1

/*
 * Function: findShortestPath
 * Usage: Path p = findShortestPath(start, finish, trace);
 * -------------------------------------------------------
 * Finds the shortest path between the nodes start and finish
 * using Dijkstra's algorithm, which keeps track of the shortest
 * paths found so far in a priority queue.  The return value is
 * a Path object, which is conceptually a vector of arcs.
 * The optional trace argument enables a trace of the operation.
 */

Path findShortestPath(Node *start, Node *finish, bool trace) {
   Map<string,double> fixed;
   PriorityQueue<Path> queue;
   Path path;
   while (start != finish) {
      if (!fixed.containsKey(start->name)) {
         fixed.put(start->name, path.getTotalCost());
         foreach (Arc *arc in start->arcs) {
            if (!fixed.containsKey(arc->finish->name)) {
               path.extend(arc);
               queue.enqueue(path, path.getTotalCost());
               if (trace) {
                  cout << "  Enqueue the path: " << path.toString()
                       << " (" << path.getTotalCost() << ")" << endl;
                  listQueue(queue);
               }
               path.retract();
            }
         }
      }
      if (queue.isEmpty()) {
         path.clear();
         break;
      }
      path = queue.dequeue();
      start = path.getFinish();
      if (trace) {
         cout << "Dequeue the shortest path: " << path.toString()
              << " (" << path.getTotalCost() << ")" << endl;
         listQueue(queue);
      }
   }
   return path;
}

void listQueue(PriorityQueue<Path> queue) {
   while (!queue.isEmpty()) {
      Path path = queue.dequeue();
      cout << "  " << path.toString() << " (" << path.getTotalCost() << ")"
           << endl;
   }
}

/* Kruskal's algorithm */

Graph<Node,Arc> findMinimumSpanningTree(Graph<Node,Arc> & g, bool trace) {
   Graph<Node,Arc> newGraph = g;
   foreach (Arc *arc in newGraph.getArcSet()) {
      newGraph.removeArc(arc);
   }
   PriorityQueue<Arc *> queue;
   foreach (Arc *arc in g.getArcSet()) {
      queue.enqueue(arc, arc->cost);
   }
   if (trace) {
      cout << "Process edges in order of cost:" << endl;
   }
   while (!queue.isEmpty()) {
      Arc *arc = queue.dequeue();
      Node *n1 = newGraph.getNode(arc->start->name);
      Node *n2 = newGraph.getNode(arc->finish->name);
      if (trace && n1->name < n2->name) {
         cout << arc->cost << ": " << n1->name << " - " << n2->name;
      }
      Set<Node *> visited;
      if (!pathExists(n1, n2, visited)) {
cout << "[adding " << n1->name << " - " << n2->name << "]" << endl;
         Arc *newArc = newGraph.addArc(n1, n2);
         newArc->cost = arc->cost;
         newArc = newGraph.addArc(n2, n1);
         newArc->cost = arc->cost;
      } else if (trace && n1->name < n2->name) {
         cout << " (not needed)";
      }
      if (trace && n1->name < n2->name) {
         cout << endl;
      }
   }
   return newGraph;
}

/* Helper functions */

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

void loadGraphFile(ifstream & infile, Graph<Node,Arc> & g) {
   TokenScanner scanner;
   scanner.ignoreWhitespace();
   scanner.scanStrings();
   scanner.scanNumbers();
   bool firstLine = true;
   bool nodesSeen = false;
   bool arcsSeen = false;
   string line;
   while (getline(infile, line)) {
      if (firstLine && line.find('.') != string::npos) {
         /* Ignore image name */
      } else if (line == "NODES") {
         if (nodesSeen) error("Misplaced NODES marker");
         nodesSeen = true;
      } else if (line == "ARCS") {
         if (arcsSeen || !nodesSeen) error("Misplaced ARCS marker");
         arcsSeen = true;
      } else if (!arcsSeen && line.find('-') == string::npos) {
         scanner.setInput(line);
         scanNode(scanner, g, true);
         nodesSeen = true;
      } else {
         scanner.setInput(line);
         scanArc(scanner, g, true);
      }
      firstLine = false;
   }
}

Node *scanNode(TokenScanner & scanner, Graph<Node,Arc> & g, bool create) {
   string name = "";
   while (true) {
      string token = scanner.nextToken();
      if (token != "" && token[0] == '"') {
         name = token.substr(1, token.length() - 2);
         break;
      } else if (token == "") {
         break;
      } else if (!isalpha(token[0])) {
         scanner.saveToken(token);
         break;
      } else {
         if (name != "") name += ' ';
         name += token;
         if (!create) break;
      }
   }
   Node *node = g.getNode(name);
   if (node == NULL) {
      if (create) {
         node = g.addNode(name);
      } else {
         error("No node named " + name);
      }
   }
   return node;
}

Arc *scanArc(TokenScanner & scanner, Graph<Node,Arc> & g, bool create) {
   Node *n1 = scanNode(scanner, g, create);
   bool bidirectional = true;
   string token = scanner.nextToken();
   if (token == "-") {
      token = scanner.nextToken();
      if (token == ">") {
         bidirectional = false;
      } else {
         scanner.saveToken(token);
      }
   } else {
      scanner.saveToken(token);
   }
   Node *n2 = scanNode(scanner, g, create);
   double cost = 1;
   token = scanner.nextToken();
   bool parenthesized = false;
   if (token == "(") {
      parenthesized = true;
      token = scanner.nextToken();
   }
   if (token != "") cost = stringToReal(token);
   if (parenthesized) scanner.verifyToken(")");
   Arc *arc = g.addArc(n1, n2);
   arc->cost = cost;
   if (bidirectional) {
      arc = g.addArc(n2, n1);
      arc->cost = cost;
   }
   return arc;
}
