/** Node Header file
**	
**	Author: Dominick Moreno
**	Project: Dijkstra Take Two
**
**		A graph is defined as a network of Nodes. Each Node must keep track of all
**	the other Nodes it is adjacent to. Additionally it keeps track of the distance
**	to each such Node. This is done by using two Vectors, adjacentNode and
**	adjacentNodeDistance, respectively. 
**
**		Each time a Node is instantiated it will be assigned a nodeID. That nodeID
**	is what defines one Node as being distinct from another. This assignment occurs
**	using a private static function.
**
**		Note the three constructors:
**			1. Default constructor
**			2. Null pointer constructor
**			3. Vector of Nodes and distances constructor
**
**		The first two exist because a small "feature" of my Collections abstract
**	class where the default constructor of the encapsulated object (in this case
**	Node) will be called to fill the Vector. This means we can't allow the default
**	constructor to be called like this because of the assignment of nodeIDs. Thus
**	I need the default constructor to do nothing. The constructor that takes a
**	void* pointer (i.e. NULL) is the one that instantiates the Node properly for
**	use.
**/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Vector.h"

class Node {
public:
	//If I weren't lazy I would make a PathWeight class and represent
	//infinity that way
	static const int INFINITE_PATH_WEIGHT = 7000000;

	Node();
	Node(void *unusedPtr);
	Node(Vector<Node*> *nodes, Vector<int> *distances); //untested
	~Node();

	void connectNode(Node *otherNode, int distance);
	bool doesNodeConnect(Node *otherNode);
	int getDistanceToNode(Node *otherNode);
	int getNodeID();
	Vector<Node *> *getAdjacentNodes();
	bool operator==(const Node& other);
	bool operator!=(const Node& other);

protected:
	Vector<Node*> *adjacentNodes = NULL;
	Vector<int> *adjacentNodesDistance = NULL;
private:
	//nodeIDs determine Node identity, so we want to be very exclusive with
	//what is allowed to modify them
	static int nodeCount;
	static int mGenerateNodeID();
	int nodeID;
};

#endif