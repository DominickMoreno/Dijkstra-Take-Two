/** Graph header file
**	
**	Author: Dominick Moreno
**	Project: Dijkstra Take Two
**
**		A Graph is a Set of Nodes. The only meaningful operation that can be done
**	on a Graph is finding the path between two given Nodes (since that's the only
**	point of this project.
**
**		Further work that needs to be done:
**			*implement graph file parsing
**			*further debugging of the Dijkstra algorithm
**			*investigate memory leaks
**			*make larger graph test cases
**			*make a Hash object to bring the findShortestPath function down from O(n^2) -> O(n)
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

#include "Set.h"
#include "Node.h"
#include "Path.h"

class Graph : public Set<Node*> {
public:
	static Set<Node*> *parseGraphFromFile(std::string fileName);
	
	Path* getPathBetweenNodes(Node* startNode, Node* endNode);
private:
	int getIndexOfNodeInSet(Node* startNode);
};

#endif