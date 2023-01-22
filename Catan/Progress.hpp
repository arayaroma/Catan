#pragma once
#include "Card.hpp"

/*
    6x Progress
    To be shopped:
    1 Mineral + 1 Wool + 1 Wheat
*/

class Progress : public Card {
public:
  Progress() {}
  Progress(string imagePath) { this->imagePath = imagePath; }

  Progress(string type, string imagePath) {
    this->type = type;
    this->imagePath = imagePath;
  }

  void toString() {}
};
