/** Path implementation file
**
**	Author: Dominick Moreno
**	Project: Dijkstra Take Two
*/

#include <iostream>

#include "Path.h"
#include "Vector.h"
#include "Node.h"

int Path::getPathWeight() {
	int pathWeight = 0;
	Node *currentNode;
	Node *nextNode;

	//path must have at least two nodes
	if (getSize() < 2) {
		return Node::INFINITE_PATH_WEIGHT;
	}

	//Add up all the consecutive distances between adjacent nodes
	for (int i = 0; i < getSize() - 1; i++) {
		currentNode = this->get(i);
		nextNode = this->get(i + 1);

		if (!currentNode->doesNodeConnect(nextNode)) {
			std::cout << "invalid path" << std::endl;
			return Node::INFINITE_PATH_WEIGHT;
		}

		pathWeight += currentNode->getDistanceToNode(nextNode);
	}

	return pathWeight;
}