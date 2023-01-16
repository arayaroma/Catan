#include "Edge.hpp"
#include <cstddef>

Edge::Edge(Vertex* destinyVertex) {
	this->destinyVertex = destinyVertex;
	next = nullptr;
}