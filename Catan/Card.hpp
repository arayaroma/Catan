#pragma once
#include <iostream>
class Card {
protected:
  std::string type, url;

public:
  Card() {}
  Card(std::string, std::string);

  virtual void toString() = 0;
};
