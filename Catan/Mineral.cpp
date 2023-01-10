#include "Mineral.hpp"

Mineral::Mineral() {}

const char *Mineral::getName() const { return this->name; }

const char *Mineral::getImagePath() const { return this->imagePath; }

int Mineral::getTotalCards() const { return this->totalCards; }