#include "City.hpp"

City::City() { this->worthPoints = 2; }

City::City(std::string type, std::string url, double x, double y) {
  this->type = type;
  this->url = url;
  this->posx = x;
  this->posy = y;
}