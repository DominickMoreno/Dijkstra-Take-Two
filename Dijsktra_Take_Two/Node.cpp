/** Node implementation file
**
**	Author: Dominick Moreno
**	Project: Dijkstra Take Two
*/

#include <iostream>
#include "Vector.h"
#include "Node.h"

int Node::nodeCount = 0;

//private static function used to assign Node IDs
int Node::mGenerateNodeID() {
	std::cout << "! About to assign Node ID: " << nodeCount << std::endl;
	return nodeCount++;
}

Node::Node() {}

//Default constructor - note that it does not instantiate the adjacentNodes
//vectors, since there's no reason to because we don't have any data to populate
//them with. This also has the handy side effect of avoiding an infinite loop...
Node::Node(void *unusedPtr) {
	nodeID = mGenerateNodeID();
}

//Untested method of construction - "should" work
Node::Node(Vector<Node*> *nodes, Vector<int> *distances) {
	
	if (nodes->getSize() != distances->getSize()) {
		std::cout << "size of nodes and distances not in agreement." <<
			" Hold on to your butts - it's gonna get nasty" << std::endl;
	}
	
	adjacentNodes = new Vector<Node*>();
	adjacentNodesDistance = new Vector<int>();

	for (int i = 0; i < nodes->getSize(); i++) {
		this->connectNode(nodes->get(i), distances->get(i));
	}

	nodeID = mGenerateNodeID();
}

Node::~Node() {
	delete adjacentNodes;
	delete adjacentNodesDistance;
}

//Connect one Node to another. Handles all interconnected relationships
//and any possible necessary instantiations
void Node::connectNode(Node *otherNode, int distance) {

	if (adjacentNodes == NULL && adjacentNodesDistance == NULL) {
		adjacentNodes = new Vector<Node*>();
		adjacentNodesDistance = new Vector<int>();
	}

	adjacentNodes->add(otherNode);
	adjacentNodesDistance->add(distance);

	//Connecting a node is reflective; since we're adding this list of
	//nodes to THIS node, we must add THIS node to every node in the
	//list we've been given

	//it's possible we may need to instantiate the otherNode's internal Vectors
	if (otherNode->adjacentNodes == NULL && otherNode->adjacentNodesDistance == NULL) {
		otherNode->adjacentNodes = new Vector<Node*>();
		otherNode->adjacentNodesDistance = new Vector<int>();
	}

	otherNode->adjacentNodes->add(this);
	otherNode->adjacentNodesDistance->add(distance);
}

bool Node::doesNodeConnect(Node *otherNode) {
	for (int i = 0; i < adjacentNodes->getSize(); i++) {
		if (*(adjacentNodes->get(i)) == *otherNode) {
			return true;
		}
	}

	return false;
}

//Generally should only be called AFTER checking the two Nodes
//actually connect
int Node::getDistanceToNode(Node *otherNode) {
	for (int i = 0; i < adjacentNodes->getSize(); i++) {
		if (*(adjacentNodes->get(i)) == *otherNode) {
			return adjacentNodesDistance->get(i);
		}
	}

	return INFINITE_PATH_WEIGHT;
}

//This breaks encapsulation :(
Vector<Node *> *Node::getAdjacentNodes() {
	return adjacentNodes;
}

//Returns the Node's identifier unique to the given Node
int Node::getNodeID() {
	return nodeID;
}

//Nodes are equal iff their internal reference numbers are equal
//	Note the classical way to fully implement the comparison between two
//objects is to overide "==" and "<", then define all other comparison
//operators in terms of those; however it is fundamentally meaningless to
//attempt to define one Node as being "less than" another. Hence the
//lack of a corresponding operator
bool Node::operator==(const Node& other) {
	return this->nodeID == other.nodeID;
}

bool Node::operator!=(const Node& other) {
	return this->nodeID != other.nodeID;
}