#pragma once
#include "Vertex.h"
#include "Edge.h"
class Graph
{
private:
	Vertex* firstVertex;
	int size;
public:
	Graph();
	bool isEmpty();
	Vertex* getVertex(int);
	void insertVertex(Vertex*);
	void insertEdge(Vertex* originVertex, Vertex* destinyVertex);

};

