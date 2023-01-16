#pragma once
#include "Vertex.h"
#include "Edge.h"
class Graph
{
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

