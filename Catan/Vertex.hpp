#pragma once
#include "Town.hpp"
#include <iostream>
#include "Player.hpp"
class Edge;

class Vertex {
private:
  friend class Graph;
  int vertexId;
  bool isPrinted;
  Edge *firstEdge;
  string ownerTown;
  bool isClicked;
  string landType;
public:
  Vertex *next;
  Town *town;
  Player* owner;
public:
  Vertex();
  Vertex(int, string, Town *, bool);

  int getVertexId() const { return this->vertexId; }

  void setLandType(string landType) { this->landType = landType; }
  string getLandType() { return this->landType; }
  void setOwner(Player* owner) { this->owner = owner; }
  Player* getOwner() { return this->owner; }

  Town* getTown() const { return this->town; }
  void toString() { std::cout << this->vertexId << " "; }
  bool getIsPrint() { return this->isPrinted; }
  void setIsPrinted(bool band) { this->isPrinted = band; }

  bool getIsClicked() { return this->isClicked; }
  void setIsClicked(bool band) { this->isClicked = band; }
};