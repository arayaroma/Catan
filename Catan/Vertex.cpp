#include "Vertex.hpp"

Vertex::Vertex() {
  this->vertexId = NULL;
  this->firstEdge = nullptr;
  this->townOwner = nullptr;
  this->owner = nullptr;
  this->next = nullptr;
  this->town = nullptr;
  this->_isPrinted = false;
  this->_isClicked = false;
  this->isTown = false;
  this->isCity = false;
}

Vertex::Vertex(int vertexId, string ownerTown, Town *town, bool isPrinted) {
  this->vertexId = vertexId;
  this->firstEdge = nullptr;
  this->townOwner = ownerTown;
  this->next = nullptr;
  this->town = town;
  this->_isPrinted = isPrinted;
  this->isTown = false;
  this->isCity = false;
}
