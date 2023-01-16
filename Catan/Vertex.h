#pragma once
#include <iostream>
#include "Town.hpp"
#define TAM 3;
class Edge;
class Vertex
{
private:
	int idVertex;
	std::string ownerTown;
	int ownerHexagon[3];
	Edge* firstEdge;
	friend class Graph;
public:
	Vertex* next;
	Town* town;
public:
	Vertex();
	Vertex(int,std::string, Town*);
	void toString() { std::cout << this->idVertex << "  " ; }
};

