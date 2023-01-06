#pragma once
#include "Component.hpp"
#include <string>

class Card : public Component {
private:
  std::string name;

public:
  Card() { setTypeClass(CARD); }
  Card(std::string typeCard, std::string urlCard, std::string nameCard);

  std::string getName();
  void setName(std::string NameCard);

  void to_string();

  virtual void getClassName() = 0;
};
