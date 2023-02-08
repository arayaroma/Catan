#pragma once
#include <SFML/Graphics.hpp>

class Vertex;
class Edge {
private:
  friend class Graph;
  
public:
	Edge *next;
  Vertex *destinyVertex;
  Vertex* originVertex;
  sf::RectangleShape edge;
public:
  Edge(Vertex*,Vertex *);
};
