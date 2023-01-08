#pragma once
#include "Component.hpp"

class Card : public Component {
protected:

public:
  Card() { setTypeClass(CARD); }
  Card(std::string typeCard, std::string urlCard);


  void to_string() {}
  void printHexagon(int x, int y) {}
  void toString() {}
  void getClassName() {}
  void printImage() {}
};
