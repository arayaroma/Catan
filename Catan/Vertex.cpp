#include "Vertex.h"
Vertex::Vertex(){
}
Vertex::Vertex(int id, std::string owner, Town* town) {
	this->idVertex = id;
	this->ownerTown = owner;
	this->town = town;
	next = NULL;
	firstEdge = NULL;
}
