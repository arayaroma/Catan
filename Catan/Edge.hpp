#pragma once
class Vertex;
class Edge
{
private:
	Edge* next;
	Vertex* destinyVertex;
	friend class Graph;
public:
	Edge(Vertex*);
};

