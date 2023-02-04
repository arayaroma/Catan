#pragma once
#include "Card.hpp"

/*
    6x Progress
    To be shopped:
    1 Mineral + 1 Wool + 1 Wheat
*/

class Progress : public Card {

private:
    string url;
public:
  Progress() {}


  Progress( std::string url) {
    this->url = url;
  }
  string getImagePath() { return this->url; }
  void toString() {}
};
