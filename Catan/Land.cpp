#include "Land.hpp"
Land::Land() {
  setTypeClass(LAND);
  this->type = nullptr;
  this->imagePath = nullptr;
  this->posx = NULL;
  this->posy = NULL;
}

Land::Land(string type, string imagePath, double x, double y, int idLand) {
  this->type = type;
  this->imagePath = imagePath;
  this->posx = x;
  this->posy = y;
  this->idLand = idLand;
}

void Land::setPosy(double y) { this->posy = y; }
double Land::getPosy() { return posy; }

void Land::setPosx(double x) { this->posx = x; }
double Land::getPosx() { return posx; }

void Land::setIdLand(int id) { this->idLand = id; }
int Land::getIdLand() { return idLand; }
