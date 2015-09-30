/** Path Header File
**
**	Author: Dominick Moreno
**	Project: Dijkstra Take Two
**
**		A Path is defined as a Vector of Nodes. In particular the order of the
**	Nodes, from the 0th element to the last is the order of the Nodes in the
**	Path. No error checking is done on the Nodes as they are entered - that is,
**	if two Nodes are entered consecutively into the Path but are NOT actually
**	adjacent to one another, there will be nothing to stop you from doing that.
**	However when you try to determine the path weight you'll get an "infinite"
**	distance as a return value and an error message.
*/


#ifndef PATH_H
#define PATH_H
#include <iostream>
#include "Vector.h"
#include "Node.h"

class Path : public Vector<Node*> {
public:
	int getPathWeight();
};

#endif