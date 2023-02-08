#include "Edge.hpp"

Edge::Edge(Vertex* originVertex,Vertex *destinyVertex) {
  this->destinyVertex = destinyVertex;
  this->originVertex = originVertex;
  next = nullptr;
}