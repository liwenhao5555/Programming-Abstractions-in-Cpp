/*
 * File: graphio.cpp
 * -----------------
 * This file implements the graphio.h interface.
 */

#include <iostream>
#include <fstream>
#include "graphtypes.h"
#include "set.h"
#include "strlib.h"
#include "vector.h"
using namespace std;

/* Private function prototypes */

static Node *createNode(SimpleGraph & g, string name);
static Arc *createArc(SimpleGraph & g, Node *n1, Node *n2, double cost);
static int nodeCompare(Node *n1, Node *n2);
static int arcCompare(Arc *a1, Arc *a2);

void readGraph(SimpleGraph & g, istream & infile) {
   g.nodes = Set<Node *>(nodeCompare);
   g.arcs = Set<Arc *>(arcCompare);
   string line;
   while (getline(infile, line) && line.length() > 0) {
      int hyphen = line.find("-");
      if (hyphen == string::npos) {
         createNode(g, trim(line));
      } else {
         int start2 = hyphen + 1;
         bool bidirectional = (line[start2] != '>');
         if (!bidirectional) start2++;
         int len1 = hyphen;
         int len2 = line.length() - start2;
         double cost = 1;
         int paren1 = line.find('(', hyphen);
         if (paren1 != string::npos) {
            len2 = paren1 - start2;
            int paren2 = line.find(')', paren1);
            if (paren2 == string::npos) {
               error("readGraph: Missing close parenthesis");
            }
            cost = stringToReal(line.substr(paren1 + 1, paren2 - paren1 - 1));
         }
         Node *n1 = createNode(g, trim(line.substr(0, len1)));
         Node *n2 = createNode(g, trim(line.substr(start2, len2)));
         createArc(g, n1, n2, cost);
         if (bidirectional) createArc(g, n2, n1, cost);
      }
   }
}

void writeGraph(SimpleGraph & g, ostream & outfile) {
   foreach (Node *node in g.nodes) {
      if (node->arcs.isEmpty()) {
         outfile << node->name << endl;
      } else {
         foreach (Arc *arc in node->arcs) {
            outfile << node->name << " -> " << arc->finish->name << endl;
         }
      }
   }
}

static Node *createNode(SimpleGraph & g, string name) {
   if (g.nodeMap.containsKey(name)) return g.nodeMap.get(name);
   Node *node = new Node;
   node->name = name;
   node->arcs = Set<Arc *>(arcCompare);
   g.nodes.add(node);
   g.nodeMap.put(name, node);
   return node;
}

static Arc *createArc(SimpleGraph & g, Node *n1, Node *n2, double cost) {
   Arc *arc = new Arc;
   arc->start = n1;
   arc->finish = n2;
   arc->cost = cost;
   g.arcs.add(arc);
   n1->arcs.add(arc);
   return arc;
}

static int nodeCompare(Node *n1, Node *n2) {
   if (n1->name == n2->name) return 0;
   return (n1->name < n2->name) ? -1 : +1;
}

static int arcCompare(Arc *a1, Arc *a2) {
   Node *n1 = a1->start;
   Node *n2 = a2->start;
   int cmp = nodeCompare(n1, n2);
   if (cmp != 0) return cmp;
   n1 = a1->finish;
   n2 = a2->finish;
   return nodeCompare(n1, n2);
}
