#pragma once
#include "Card.hpp"
/*
    5x VictoryPoints
    To be shopped:
    1 Mineral + 1 Wool + 1 Wheat
*/

class VictoryPoints : public Card {
private:
  std::string m_Url;

public:
  VictoryPoints() {}
  VictoryPoints(std::string url) : m_Url(url) {}
  void toString() {}
};
