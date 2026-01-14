/*
 * File: graphio.h
 * ---------------
 * This file defines the interface for a library of graph input/output
 * functions built on top of the SimpleGraph structure.
 */

#ifndef _graphio_h
#define _graphio_h

#include <iostream>
#include "graphtypes.h"

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
 *    n1 - n2
 *
 * Isolated nodes can be specified in the graph by including the
 * name of the node on a line all by itself.
 */

void readGraph(SimpleGraph & g, std::istream & infile);

/*
 * Function: writeGraph
 * Usage: writeGraph(g, outfile);
 * ------------------------------
 * Writes the contents of the graph g to the output stream in a form
 * that can then be read by readGraph.
 */

void writeGraph(SimpleGraph & g, std::ostream & outfile);

#endif
