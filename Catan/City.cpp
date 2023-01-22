#include "City.hpp"

City::City() {
  this->type = FIGURE;
  this->imagePath = ""; // Arte Town, City, Road
  this->worthPoints = 2;
  this->posX = NULL;
  this->posY = NULL;
}