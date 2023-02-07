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
    bool isRecentlybuy = false;
public:
  Progress() {}

  Progress(bool isRecentlybuy) { this->isRecentlybuy = isRecentlybuy; }
  Progress(int type, std::string url) {
    this->url = url;
    this->type = type;
  }
  string getImagePath() { return this->url; }
  int getType() { return this->type; }
  void toString() {}

  void setIsRecentlyBuy(bool band) { this->isRecentlybuy = band; }
  bool getIsRecentlyBuy() { return this->isRecentlybuy; }
};
