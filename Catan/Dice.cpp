#include "Dice.hpp"

Dice::Dice() {
  this->min = 1;
  this->max = 12;
}

int Dice::getNumber() const {
  srand((unsigned)time(nullptr));
  return rand() % (max - min + 1) + min;
}

int Dice::getActualNumber() const { return this->actualNumber; }

int Dice::rollDice() {
  actualNumber = getNumber();
  return actualNumber;
}