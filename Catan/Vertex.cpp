#include "Vertex.hpp"
Vertex::Vertex() {
	this->next = nullptr;
	this->firstEdge = nullptr;
	this->town = nullptr;
	this->vertexId = NULL;
	this->ownerTown = nullptr;
}

Vertex::Vertex(int id, string owner, Town *town) {
  this->vertexId = id;
  this->ownerTown = owner;
  this->town = town;
  this->next = nullptr;
  this->firstEdge = nullptr;
}
