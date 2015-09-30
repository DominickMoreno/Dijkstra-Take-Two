/** Graph implementation file
**
**	Author: Dominick Moreno
**	Project: Dijkstra Take Two
*/


#include <iostream>
#include <string>

#include "Set.h"
#include "Vector.h"
#include "Node.h"
#include "Path.h"

#include "Graph.h"

Set<Node*>* Graph::parseGraphFromFile(std::string fileName) {
	//TODO: this

	return NULL;
}

//private helper function
int Graph::getIndexOfNodeInSet(Node* startNode) {
	
	for (int index = 0; index < this->getSize(); index++) {
		if (*startNode == *(this->mGet(index))) {
			return index;
		}
	}

	return -1;
}

Path* Graph::getPathBetweenNodes(Node* startNode, Node* endNode) {
	Set<Node *> visitedNodes = Set<Node *>();

	//These two must correspond to the internal array of this graph
	Vector<int> distanceFromStartNode = Vector<int>();
	Vector<Node *> pathVector = Vector<Node *>();

	Vector<Node *> *currentlyAdjacentNodes = NULL;
	Node* currentNode = startNode;

	Path *finalPath = new Path();

	int indexOfStartNode = getIndexOfNodeInSet(startNode);

	//Make sure input is valid
	if (indexOfStartNode == -1) {
		std::cout << "Error: start node not in graph" << std::endl;
		return NULL;
	} else if (this->getSize() < 2) {
		std::cout << "Error: Graph doesn't have enough Nodes to make a path" << std::endl;
		return NULL;
	} else if (startNode == endNode) {
		std::cout << "Error: start and end node are the same" << std::endl;
		return NULL;
	}

	//initialize the distances
	for (int i = 0; i < this->getSize(); i++) {
		if (i == indexOfStartNode) {
			distanceFromStartNode.add(0);
			pathVector.add(startNode);
		} else {
			distanceFromStartNode.add(Node::INFINITE_PATH_WEIGHT);
			pathVector.add(NULL);
		}
	}

	//mark the starting node as visited
	visitedNodes.add(startNode);

	//we will visit all nodes and get their distances from the start
	while (this->getSize() != visitedNodes.getSize()) {
		currentlyAdjacentNodes = currentNode->getAdjacentNodes();
		int indexOfCurrentNode = getIndexOfNodeInSet(currentNode);

		//Iterate through every node adjacent to the current one that
		//has not already been visited
		for (int j = 0; j < currentlyAdjacentNodes->getSize(); j++) {
			Node *adjacentNode = currentlyAdjacentNodes->get(j);
			if (!visitedNodes.contains(adjacentNode)) {

				//If the path to an adjacent node is shorter than the distance we have recorded for it, update that distance
				int tentativeDistance = distanceFromStartNode.get(indexOfCurrentNode) + currentNode->getDistanceToNode(adjacentNode);
				int indexOfAdjacentNode = getIndexOfNodeInSet(adjacentNode);

				if (tentativeDistance < distanceFromStartNode.get(indexOfAdjacentNode)) {
					distanceFromStartNode.replace(tentativeDistance, indexOfAdjacentNode);
					pathVector.replace(currentNode, indexOfAdjacentNode);
				}
			}
		}

		//Mark this Node as visited
		visitedNodes.add(currentNode);

		//Choose the next Node to visit - must be the Node closest to the start that is yet unvisited
		int shortestDistance = Node::INFINITE_PATH_WEIGHT;
		int indexOfNextNode = -1;

		for (int n = 0; n < this->getSize(); n++) {
			if (!visitedNodes.contains(this->mGet(n))) {
				if (distanceFromStartNode.get(n) < shortestDistance) {
					indexOfNextNode = n;
				}
			}
		}

		//We don't care if indexOfNextNode was -1, since then we'll be finishing at the end of this iteration anyways
		if (indexOfNextNode != 1) {
			currentNode = this->mGet(indexOfNextNode);
		}
	}

	//We now have Vectors that contain all the information needed to build the path
	//from the start to the finish
	currentNode = this->mGet(getIndexOfNodeInSet(endNode));
	
	//Traverse through our PathVector to get the Path
	while (*currentNode != *startNode) {
		finalPath->add(currentNode);
		currentNode = pathVector.get(getIndexOfNodeInSet(currentNode));
	}

	return finalPath;
}