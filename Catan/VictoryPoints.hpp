#pragma once
#include "Card.hpp"
/*
    5x VictoryPoints
    To be shopped:
    1 Mineral + 1 Wool + 1 Wheat
*/

class VictoryPoints : public Card {
private:
    string url;

public:
  VictoryPoints() {}
  VictoryPoints(std::string url) { this->url = url; }
  string getImagePath() { return this->url; }
  void toString() {}
};
