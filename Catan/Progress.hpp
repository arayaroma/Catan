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
    int type;
public:
  Progress() {}


  Progress(int type, std::string url) {
    this->url = url;
    this->type = type;
  }
  string getImagePath() { return this->url; }
  int getType() { return this->type; }
  void toString() {}
};
