#include "Vertex.h"
Vertex::Vertex(){
	next = NULL;
	firstEdge = NULL;
}
Vertex::Vertex(int id, std::string owner, Town* town) {
	this->idVertex = id;
	this->ownerTown = owner;
	this->town = town;
}
