#include "Vertex.hpp"
Vertex::Vertex() {}

Vertex::Vertex(int id, std::string owner, Town *town) {
  this->vertexId = id;
  this->ownerTown = owner;
  this->town = town;
  next = nullptr;
  firstEdge = nullptr;
}
