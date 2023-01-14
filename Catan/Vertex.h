#pragma once
#include "Town.hpp"
#include <iostream>

#define TAM 3;
class Edge;
class Vertex {
private:
  friend class Graph;
  int idVertex;
  std::string ownerTown;
  int ownerHexagon[3];
  Edge *firstEdge;

public:
  Vertex *next;
  Town *town;

public:
  Vertex();
  Vertex(int, std::string, Town *);
};
