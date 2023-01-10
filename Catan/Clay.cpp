#include "Clay.hpp"

Clay::Clay() {}

const char *Clay::getName() const { return this->name; }

const char *Clay::getImagePath() const { return this->imagePath; }

int Clay::getTotalCards() const { return this->totalCards; }
