#pragma once
#include "Edge.hpp"
#include "Vertex.hpp"

class Graph {
private:
  int size;

public:
  Vertex *firstVertex;

public:
  Graph();
  bool isEmpty();
  Vertex *getVertex(int);
  int getVertexId(Vertex *);
  void vertexXY();
  void insertVertex(Vertex *);
  void insertOwnerHexagon(int, int vecOwners[]);
  void insertEdge(int origin, int destiny);
  void showAdjacencyList();
  
};
