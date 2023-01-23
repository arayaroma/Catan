#pragma once
class Vertex;
class Edge {
private:
  friend class Graph;
  Edge *next;
  Vertex *destinyVertex;

public:
  Edge(Vertex *);
};
