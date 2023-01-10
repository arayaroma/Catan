#pragma once
#include <cstdlib>
#include <iostream>

enum Numbers {
  one,
  two,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine,
  ten,
  eleven,
  twelve
};

class Dice {
private:
  int min, max;

public:
  Dice();

  int getNumber() const;
  int rollDice() const;
};
