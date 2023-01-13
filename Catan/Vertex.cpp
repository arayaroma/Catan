#include "Vertex.h"
Vertex::Vertex(){
	next = NULL;
	firstEdge = NULL;
}
Vertex::Vertex(int id, std::string owner, int idHexagon, Town* town) {
	this->idVertex = id;
	this->ownerTown = owner;
	this->idHexagon = idHexagon;
	this->town = town;
}
