#include "Wool.hpp"

Wool::Wool() {}

const char *Wool::getName() const { return this->name; }

const char *Wool::getImagePath() const { return this->imagePath; }

int Wool::getTotalCards() const { return this->totalCards; }