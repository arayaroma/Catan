#pragma once
#include "Town.hpp"
#include <iostream>

#define TAM 3;

class Edge;

class Vertex {
private:
	friend class Graph;
	int idVertex;
	Edge* firstEdge;
	int ownerHexagon[3];
	std::string ownerTown;

public:
	Vertex* next;
	Town* town;

public:
	Vertex();
	Vertex(int, std::string, Town*);
	void toString() { std::cout << this->idVertex << "  "; }
};