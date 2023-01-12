#include "Vertex.h"

Vertex::Vertex(int id, std::string owner, int idHexagon) {
	next = NULL;
	firstEdge = NULL;
	this->idVertex = id;
	this->ownerTown = owner;
	this->idHexagon = idHexagon;
}
