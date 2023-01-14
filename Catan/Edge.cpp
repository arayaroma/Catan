#include "Edge.h"
#include <cstddef>

Edge::Edge(Vertex* destinyVertex) {
	this->destinyVertex = destinyVertex;
	next = NULL;
}