#pragma once
#include "Player.hpp"
#include "Town.hpp"
#include <SFML/Graphics.hpp>

#define log(x) std::cout << x << std::endl;

class Edge;

class Vertex {
public:
  std::string to_string() const {
    return std::to_string(vertexId) + delimiter + townOwner +
           bool_to_string(_isPrinted) + delimiter + bool_to_string(_isClicked) +
           delimiter + bool_to_string(isTown) + delimiter +
           bool_to_string(isCity) /*+ delimiter + owner->to_string() */+ delimiter +
           town->to_string();
  }

private:
  friend class Graph;
  int vertexId;
  string townOwner;
  bool _isPrinted;
  bool _isClicked;
  sf::Vertex vertex;

  bool isTown;
  bool isCity;

public:
  Player *owner;
  Vertex *next;
  Town *town;
  Edge *firstEdge;

public:
  Vertex();
  Vertex(int, string, Town *, bool);

  int getVertexId() const { return this->vertexId; }

  void setOwner(Player *owner) { this->owner = owner; }
  Player *getOwner() { return this->owner; }

  Town *getTown() const { return this->town; }
  void setPrinted(bool isPrinted) { this->_isPrinted = isPrinted; }
  bool isPrinted() const { return this->_isPrinted; }

  void setIsTown(bool isTown) { this->isTown = isTown; }
  bool getIsTown() const { return this->isTown; }

  void setIsCity(bool isCity) { this->isCity = isCity; }
  bool getIsCity() const { return this->isCity; }

  void setClicked(bool isClicked) { this->_isClicked = isClicked; }
  bool isClicked() const { return this->_isClicked; }

  void toString() { log(this->vertexId); }
};