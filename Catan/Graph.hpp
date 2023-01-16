#pragma once
#include "Vertex.hpp"
#include "Edge.hpp"

class Graph{
private:
	int size;

public:
	Vertex* firstVertex;

public:
	Graph();
	bool isEmpty();
	Vertex* getVertex(int);
	int getIdVertex(Vertex*);
	void vertexXY();
	void insertVertex(Vertex*);
	void insertOwnerHexagon(int, int vecOwners[]);
	void insertEdge(int origin, int destiny);
	void showListAdjacency();
};

