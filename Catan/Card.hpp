#pragma once
#include "Component.hpp"
class Card : public Component {
public:
  std::string to_string() const { return type + delimiter + imagePath; }

public:
  Card() {}
  Card(string, string);
  string getType() const override { return CARD; }
  string getImagePath() override { return this->imagePath; }
  void toString() override {}
};
