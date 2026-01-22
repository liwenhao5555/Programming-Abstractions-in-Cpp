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
Vector<Arc *> findShortestPath(Node *start, Node *finish, bool trace);
double getPathCost(const Vector<Arc *> & path);
string pathToString(const Vector<Arc *> & path);
Graph<Node,Arc> findMinimumSpanningTree(Graph<Node,Arc> & g, bool trace);

void visit(Node *node);
void listNode(Node *node);
void loadGraphFile(ifstream & infile, Graph<Node,Arc> & g);
Node *scanNode(TokenScanner & scanner, Graph<Node,Arc> & g);
void addNode(TokenScanner & scanner, Graph<Node,Arc> & g);
void addArc(TokenScanner & scanner, Graph<Node,Arc> & g);
int nodeCompare(Node *n1, Node *n2);
int arcCompare(Arc *a1, Arc *a2);

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
   addArc(scanner, *gp);
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
   if (n1 == n2) {
      cout << "Start and finish are the same node" << endl;
   } else {
      Vector<Arc *> path = findShortestPath(n1, n2, trace);
      if (path.isEmpty()) {
         cout << "No path exists" << endl;
      } else {
         cout << pathToString(path)
              << " (" << getPathCost(path) << ")" << endl;
      }
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
   addNode(scanner, *gp);
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
      if (visited.contains(node)) {
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
 * Usage: Vector<Arc *> path = findShortestPath(start, finish, trace);
 * -------------------------------------------------------------------
 * Finds the shortest path between the nodes start and finish using
 * Dijkstra's algorithm, which keeps track of the shortest paths in
 * a priority queue.  The function returns a vector of arcs, which is
 * empty if start and finish are the same node or if no path exists.
 * The optional trace argument enables a trace of the operation.
 */

Vector<Arc *> findShortestPath(Node *start, Node *finish, bool trace) {
   Vector<Arc *> path;
   PriorityQueue< Vector<Arc *> > queue;
   Map<string,double> fixed;
   while (start != finish) {
      if (fixed.containsKey(start->name)) {
         if (trace) {
            cout << "Ignore this path because the distance to "
                 << start->name << " is fixed" << endl;
         }
      } else {
         if (trace) {
            cout << "Fix distance to " << start->name
                 << " at " << getPathCost(path) << endl;
         }
         fixed.put(start->name, getPathCost(path));
         if (trace) {
            cout << "Process the arcs out of " << start->name << " (";
            int count = 0;
            foreach (Arc *arc in start->arcs) {
               if (count > 0) cout << ", ";
               cout << arc->finish->name;
               count++;
            }
            cout << ")" << endl;
         }
         foreach (Arc *arc in start->arcs) {
            if (fixed.containsKey(arc->finish->name)) {
               if (trace) {
                  cout << "  Ignore " << arc->finish->name
                       << " because its distance is fixed" << endl;
               }
            } else {
               path.add(arc);
               queue.enqueue(path, getPathCost(path));
               if (trace) {
                  cout << "  Enqueue the path: " << pathToString(path)
                       << " (" << getPathCost(path) << ")" << endl;
               }
               path.remove(path.size() - 1);
            }
         }
      }
      if (queue.isEmpty()) {
         path.clear();
         return path;
      }
      path = queue.dequeue();
      start = path[path.size() - 1]->finish;
      if (trace) {
         cout << "Dequeue the shortest path: " << pathToString(path)
              << " (" << getPathCost(path) << ")" << endl;
      }
   }
   return path;
}

/*
 * Function: getPathCost
 * Usage: double cost = getPathCost(path);
 * ---------------------------------------
 * Returns the total cost of the path, which is just the sum of the
 * costs of the arcs.
 */

double getPathCost(const Vector<Arc *> & path) {
   double cost = 0;
   foreach (Arc *arc in path) {
      cost += arc->cost;
   }
   return cost;
}

/*
 * Function: pathToString
 * Usage: cout << pathToString(path);
 * ----------------------------------
 * Converts the path to a string.
 */

string pathToString(const Vector<Arc *> & path) {
   string str = "";
   foreach (Arc *arc in path) {
      if (str == "") str = arc->start->name;
      str += "->" + arc->finish->name;
   }
   return str;
}

/* Kruskal's algorithm */

Graph<Node,Arc> findMinimumSpanningTree(Graph<Node,Arc> & g, bool trace) {
   Graph<Node,Arc> newGraph;
   foreach (Node *oldNode in g.getNodeSet()) {
      Node *newNode = new Node;
      *newNode = *oldNode;
      newNode->arcs.clear();
      newGraph.addNode(newNode);
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
         Arc *newArc = new Arc;
         newArc->start = n1;
         newArc->finish = n2;
         newArc->cost = arc->cost;
         n1->arcs.add(newArc);
         newGraph.addArc(newArc);
         newArc = new Arc;
         newArc->start = n2;
         newArc->finish = n1;
         newArc->cost = arc->cost;
         n2->arcs.add(newArc);
         newGraph.addArc(newArc);
      } else if (trace && n1->name < n2->name) {
         cout << " (not needed) ";
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
         addNode(scanner, g);
         nodesSeen = true;
      } else {
         scanner.setInput(line);
         addArc(scanner, g);
      }
      firstLine = false;
   }
}

Node *scanNode(TokenScanner & scanner, Graph<Node,Arc> & g) {
   string name = scanner.nextToken();
   if (name[0] == '"') name = name.substr(1, name.length() - 2);
   return g.getNode(name);
}

void addNode(TokenScanner & scanner, Graph<Node,Arc> & g) {
   string name = scanner.nextToken();
   if (name[0] == '"') name = name.substr(1, name.length() - 2);
   Node *node = g.addNode(name);
}

void addArc(TokenScanner & scanner, Graph<Node,Arc> & g) {
   Node *n1 = scanNode(scanner, g);
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
   Node *n2 = scanNode(scanner, g);
   double cost = 1;
   token = scanner.nextToken();
   if (token != "") cost = stringToReal(token);
   Arc *arc = new Arc;
   arc->start = n1;
   arc->finish = n2;
   arc->cost = cost;
   g.addArc(arc);
   if (bidirectional) {
      arc = new Arc;
      arc->start = n2;
      arc->finish = n1;
      arc->cost = cost;
      n2->arcs.add(arc);
      g.addArc(arc);
   }
}

int nodeCompare(Node *n1, Node *n2) {
   if (n1->name == n2->name) return 0;
   return (n1->name < n2->name) ? -1 : +1;
}

int arcCompare(Arc *a1, Arc *a2) {
   Node *n1 = a1->start;
   Node *n2 = a2->start;
   int cmp = nodeCompare(n1, n2);
   if (cmp != 0) return cmp;
   n1 = a1->finish;
   n2 = a2->finish;
   return nodeCompare(n1, n2);
}
