#include "Vertex.hpp"
Vertex::Vertex() {
	this->next = nullptr;
	this->firstEdge = nullptr;
	this->town = nullptr;
	this->vertexId = NULL;
	this->ownerTown = nullptr;
	this->isPrinted = false;
}

Vertex::Vertex(int id, string owner, Town *town, bool isPrinted) {
  this->vertexId = id;
  this->ownerTown = owner;
  this->town = town;
  this->next = nullptr;
  this->firstEdge = nullptr;
  this->isPrinted = isPrinted;
}
