#pragma once
#include "Edge.hpp"
#include "Vertex.hpp"
#include <string>
#define log(x) std::cout << x << std::endl;

class Graph {
public:
  std::string to_string() const {
    return std::to_string(size) + delimiter + firstVertex->to_string();
  }

private:
  int size;

public:
  Vertex *firstVertex;

public:
  Graph();
  bool isEmpty();
  Vertex *getVertex(int);
  int getVertexId(Vertex *);
  void vertexXY();
  void insertVertex(Vertex *);
  void insertEdge(int origin, int destiny);
  void showAdjacencyList();
};
