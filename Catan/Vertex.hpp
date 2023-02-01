#pragma once
#include "Town.hpp"
#include <iostream>

class Edge;

class Vertex {
private:
  friend class Graph;
  int vertexId;
  bool isPrinted;
  Edge *firstEdge;
  string ownerTown;
  bool isClicked;
public:
  Vertex *next;
  Town *town;

public:
  Vertex();
  Vertex(int, string, Town *, bool);

  int getVertexId() const { return this->vertexId; }
  Town* getTown() const { return this->town; }
  void toString() { std::cout << this->vertexId << " "; }
  bool getIsPrint() { return this->isPrinted; }
  void setIsPrinted(bool band) { this->isPrinted = band; }

  bool getIsClicked() { return this->isClicked; }
  void setIsClicked(bool band) { this->isClicked = band; }
};