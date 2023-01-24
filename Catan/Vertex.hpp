#pragma once
#include "Town.hpp"
#include <iostream>

#define TAM 3;

class Edge;

class Vertex {
private:
  friend class Graph;
  int vertexId;
  Edge *firstEdge;
  int ownerHexagon[3];
  std::string ownerTown;

public:
  Vertex *next;
  Town *town;

public:
  Vertex();
  Vertex(int, std::string, Town *);

  int getVertexId() const { return this->vertexId; }
  Town* getTown() const { return this->town; }
  void toString() { std::cout << this->vertexId << " "; }
};