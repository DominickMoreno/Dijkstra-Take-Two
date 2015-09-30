/** Driver file for the Dijkstra Take Two
**
**	Author: Dominick Moreno
**	Github: github.com/DominickMoreno
**
**		This is my second published (but fifth overall attempt) at
**	creating a relatively simple program to implement Dijkstra's
**	algorithm using only the Abstract Data Types (ADTs) that I build
**	myself. Previous iterations of this project were done in C, C++ and
**	Java. The Java version was an assignment for a class, and so was
**	completed, but made extensive use of ADTs from the Java Collection
**	interface. The two C iterations were unable to implement Dijkstra's.
**	Finally the previous version in C++ can be seen on my Github, but it
**	became an overly convoluted mess that was unnecessarily complex just
**	to represent the graph.
**
**		What will (hopefully) be my final attempt at this project will
**	be done by building my more basic structures first - Set, Vector,
**	Node and Path. I will then make my Graph a Set of Nodes, from which
**	a (shortest) Path between any two Nodes (if any exists) can be
**	calculated. 
**
**		Instead of using a menu-based selection system like the previous
**	C++ did (for some reason), this program takes the file containing the
**	Graph in at the command line, parses it into a Graph object, and
**	calculates the shortest path between two given points.
**
*/

#include "stdafx.h"
#include "Collection.h"
#include "Set.h"
#include "Vector.h"
#include "Node.h"
#include "Path.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
	std::string line;
	std::ifstream graphFile; 
	graphFile.open(argv[1]);  

	/*
	if (graphFile.is_open()) {
		std::cout << "file opened, will read first line" << std::endl;

		while (std::getline(graphFile, line)) {
			std::cout << line << std::endl;
		}

	}
	else {
		std::cout << "file could not be opened" << std::endl;
	}
	*/
	graphFile.close();
	system("pause");
    return 0;
}

