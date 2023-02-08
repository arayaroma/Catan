#pragma once
#include "Card.hpp"
/*
    14x Knights
    To be shopped:
    1 Mineral + 1 Wool + 1 Wheat
*/

class Knight : public Card {
public:
  std::string to_string() const { return type + imagePath + delimiter + url; }

private:
  string url;

public:
  Knight() {}
  Knight(std::string url) { this->url = url; }

  string getImagePath() { return this->url; }
  void toString() {}
};
