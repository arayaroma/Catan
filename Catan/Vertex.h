#pragma once
#include <iostream>
class Edge;
class Vertex
{
private:
	int idVertex;
	std::string ownerTown;
	int idHexagon;
	Vertex* next;
	Edge* firstEdge;
	friend class Graph;
public:
	Vertex();
	Vertex(int,std::string,int);
};

