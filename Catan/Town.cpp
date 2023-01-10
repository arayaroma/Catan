#include "Town.hpp"

Town::Town() { this->worthPoints = 1; }
Town::Town(std::string typeLand, std::string urlLand, double x, double y) {
	this->type = typeLand;
	this->url = urlLand;
	this->posx = x;
	this->posy = y;
}