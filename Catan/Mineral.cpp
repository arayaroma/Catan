#include "Mineral.hpp"

Mineral::Mineral() {}

const char *Mineral::getName() const { return this->name; }

int Mineral::getTotalCards() const { return this->totalCards; }