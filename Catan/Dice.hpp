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
  int actualNumber;
  int min, max;

public:
  Dice();

  int getActualNumber() const;
  int rollDice();

private:
  int getNumber() const;
};
