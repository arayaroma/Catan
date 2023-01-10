#include "Wood.hpp"

Wood::Wood() {}

const char *Wood::getName() const { return this->name; }

const char *Wood::getImagePath() const { return this->imagePath; }

int Wood::getTotalCards() const { return this->totalCards; }