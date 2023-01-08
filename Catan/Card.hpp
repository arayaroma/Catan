#pragma once
#include "Component.hpp"

class Card : public Component {
protected:
  std::string name;

public:
  Card() { setTypeClass(CARD); }
  Card(std::string typeCard, std::string urlCard, std::string nameCard);

  std::string getName();
  void setName(std::string NameCard);

  void to_string() {}
  void printHexagon(int x, int y) {}
  void toString() {}
  void getClassName() {}
  void printImage() {}
};
