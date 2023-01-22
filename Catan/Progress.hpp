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


  Progress( std::string url) {
    this->type = type;
    this->imagePath = imagePath;
  }

  void toString() {}
};
