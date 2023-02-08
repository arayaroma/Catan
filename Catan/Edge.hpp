#pragma once
// #include "Vertex.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class Vertex;
class Edge {

private:
  friend class Graph;

public:
  Edge *next;
  Vertex *destinyVertex;
  Vertex *originVertex;
  sf::RectangleShape edge;

public:
  Edge(Vertex *, Vertex *);
};
