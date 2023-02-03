#include "Land.hpp"

Land::Land() {
  this->type = "";
  this->imagePath = "";
  this->posX = NULL;
  this->posY = NULL;
  this->townsList = new list<Vertex*>();
}

Land::Land(string type, string imagePath, double posX, double posY, int landId) {
  this->typeland = type;
  this->imagePath = imagePath;
  this->posX = posX;
  this->posY = posY;
  this->landId = landId;
  this->townsList = new list<Vertex*>();
}

void Land::setPosY(double posY)  { this->posY = posY; }
double Land::getPosY() const { return this->posY; }

void Land::setPosX(double posX) { this->posX = posX; }
double Land::getPosX() const { return this->posX; }

void Land::setLandId(int landId) { this->landId = landId; }
int Land::getLandId() const { return this->landId; }
