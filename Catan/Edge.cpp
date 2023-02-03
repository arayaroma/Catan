#include "Edge.hpp"

Edge::Edge(Vertex *destinyVertex) {
  this->destinyVertex = destinyVertex;
  next = nullptr;
}