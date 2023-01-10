#include "Road.hpp"

Road::Road() { this->worthPoints = 0; }
Road::Road(std::string typeLand, std::string urlLand, double x, double y) {
	this->type = typeLand;
	this->url = urlLand;
	this->posx = x;
	this->posy = y;
}