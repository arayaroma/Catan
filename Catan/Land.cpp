#include "Land.hpp"

Land::Land() {
  this->type = "";
  this->imagePath = "";
  this->posX = NULL;
  this->posY = NULL;
}

Land::Land(int landId, string imagePath, double posX, double posY) {
  this->type = LAND;
  this->imagePath = imagePath;
  this->posX = posX;
  this->posY = posY;
  this->landId = landId;
}

void Land::setPosY(double posY)  { this->posY = posY; }
double Land::getPosY() const { return this->posY; }

void Land::setPosX(double posX) { this->posX = posX; }
double Land::getPosX() const { return this->posX; }

void Land::setLandId(int landId) { this->landId = landId; }
int Land::getLandId() const { return this->landId; }
