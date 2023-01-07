#include "Land.hpp"
Land::Land() {
    setTypeClass(LAND);
    this->type = "";
    this->url = "";
    this->posx = 0;
    this->posy = 0;
}

Land::Land(std::string typeLand, std::string urlLand, double x, double y) {
  this->type = typeLand;
  this->url = urlLand;
  this->posx = x;
  this->posy = y;
}

void Land::setPosy(double y) { this->posy = y; }
double Land::getPosy() { return posy; }

void Land::setPosx(double x) { this->posx = x; }
double Land::getPosx() { return posx; }
