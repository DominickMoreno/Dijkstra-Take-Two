Author: Dominick Moreno
Project: Dijkstra Take Two
E-mail: Dominickmoreno92@gmail.com
Github: github.com/DominickMoreno

About this project:
	This project does a basic implementation of Dijkstra's algorithm without using STL functions (e.g. std::vector). The challenge was to build all of my Abstract Data Types (ADTs) myself and see if I could successfully use them to implement a famous algorithm.

About the previous version(s) of this project:
	There are two versions of this project on my Github. The first, simply labled "Dijkstra", was my first attempt at this project in C++. There were multiple issues with it. One it was menu driven (as opposed to just providing the graph in a file on the command line), which was just silly. Another was that it became overly convoluted. I made Edges and Nodes their own distinct classes which caused for completely unnecessary interdependencies between classses. The entire thing was too convoluted and badly documented so I decided to start over.

	However there have been a few other versions of this project as well. I made two previous attempts in C for class projects. I've also succesfully implemented Dijkstra's in Java for another class project while making extensive use of classes that implement the Collections interface.

Structure:
	This project is organized as follows:

	*Abstract Class Template Collection
		*Child Class Template Set
			*Child Class Graph (is a Set of Nodes)
		*Child Class Template Vector
			*Child Class Path (is a Vector of Nodes)
	*Class Node

Future work:
	I'm fairly happy with how most of this project has turned out. Namely how succesful my implementation of Set and Vector were. However there are a few things I'd like to work out:
			*implement graph file parsing
			*further debugging of the Dijkstra algorithm
			*investigate memory leaks
			*make larger graph test cases
			*make a Hash object to bring the findShortestPath function down from O(n^2) -> O(n)