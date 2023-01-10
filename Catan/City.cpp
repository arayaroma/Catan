#include "City.hpp"

City::City() { this->worthPoints = 2; }
City::City(std::string typeLand, std::string urlLand, double x, double y) {
	this->type = typeLand;
	this->url = urlLand;
	this->posx = x;
	this->posy = y;
}