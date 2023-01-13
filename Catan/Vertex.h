#pragma once
#include <iostream>
#include "Town.hpp"
class Edge;
class Vertex
{
private:
	Town* town;
	int idVertex;
	std::string ownerTown;
	int idHexagon;
	Vertex* next;
	Edge* firstEdge;
	friend class Graph;
public:
	Vertex();
	Vertex(int,std::string,int, Town*);
};

