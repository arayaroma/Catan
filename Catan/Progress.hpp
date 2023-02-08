#pragma once
#include "Card.hpp"

/*
    6x Progress
    To be shopped:
    1 Mineral + 1 Wool + 1 Wheat
*/

inline std::string const bool_to_string(bool b) { return b ? "true" : "false"; }
class Progress : public Card {
public:
  std::string to_string() const {
    return imagePath + delimiter + url + delimiter + std::to_string(type) +
           delimiter + bool_to_string(isRecentlybuy);
  }

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
