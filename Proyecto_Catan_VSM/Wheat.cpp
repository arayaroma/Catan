#include "Wheat.hpp"

Wheat::Wheat() {}

const char *Wheat::getName() const { return this->name; }

const char *Wheat::getImagePath() const { return this->imagePath; }

const int Wheat::getTotalCards() const { return this->totalCards; }