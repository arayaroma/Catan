#include "Dice.hpp"

Dice::Dice() {
  this->min = 1;
  this->max = 12;
}

int Dice::getNumber() const {
  srand(time(NULL));
  return rand() % (max - min + 1) + min;
}

int Dice::rollDice() const { return getNumber(); }