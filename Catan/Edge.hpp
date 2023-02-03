#pragma once
#include <SFML/Graphics.hpp>

class Vertex;
class Edge {
private:
  friend class Graph;
  Edge *next;
  Vertex *destinyVertex;
  sf::RectangleShape edge;

public:
  Edge(Vertex *);
};
