#pragma once
#include "Town.hpp"
#include <iostream>

class Edge;

class Vertex {
private:
  friend class Graph;
  int vertexId;
  Edge *firstEdge;
  string ownerTown;

public:
  Vertex *next;
  Town *town;

public:
  Vertex();
  Vertex(int, string, Town *);

  int getVertexId() const { return this->vertexId; }
  Town* getTown() const { return this->town; }
  void toString() { std::cout << this->vertexId << " "; }
};