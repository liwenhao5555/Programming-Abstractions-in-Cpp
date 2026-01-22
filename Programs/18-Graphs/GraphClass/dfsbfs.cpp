/*
 * File: dfsbfs.h
 * --------------
 * This file defines the interface for a library of graph algorithms
 * built on top of the SimpleGraph structure.
 */

#ifndef _dfsbfs_h
#define _dfsbfs_h

/*
 * Function: readGraph
 * Usage: readGraph(g, infile);
 * ----------------------------
 * Reads in the contents of a graph from the specified input stream,
 * which must be open for input.  Each line of the file must be either
 * a unidirectional arc in the form
 *
 *    n1 -> n2
 *
 * or a bidirectional arc specified as
 *
 *    n1 <-> n2
 *
 * Isolated nodes can be specified in the graph by including the
 * name of the node on a line all by itself.
 */

void readGraph(SimpleGraph & g, istream & infile);

/*
 * Function: writeGraph
 * Usage: writeGraph(g, outfile);
 * ------------------------------
 * Writes the contents of the graph g to the output stream in a form
 * that can then be read by readGraph.
 */

void writeGraph(SimpleGraph & g, string name);

/*
 * Function: breadthFirstSearch
 * Usage: breadthFirstSearch(start);
 *        breadthFirstSearch(start, finish);
 * -----------------------------------------
 * Calls visit(node) for every node in a breadth-first search expansion
 * from the start node.  If the optional finish node is supplied, the
 * breadthFirstSearch function continues until no more nodes are reachable.
 * The breadth-first algorithm visits nodes in order by their distance in
 * hops from the start node.
 */

void breadthFirstSearch(Node *start, Node *finish = NULL);

/*
 * Function: depthFirstSearch
 * Usage: depthFirstSearch(start);
 *        depthFirstSearch(start, finish);
 * ---------------------------------------
 * Calls visit(node) for every node in a depth-first search expansion
 * from the start node.  If the optional finish node is supplied, the
 * depthFirstSearch function continues until no more nodes are reachable.
 * The depth-first algorithm explores the graph recursively, choosing each
 * arc from the start node and visiting every node reachable along that
 * path before moving on to the next arc.
 */

void depthFirstSearch(Node *start, Node *finish = NULL);

#endif
