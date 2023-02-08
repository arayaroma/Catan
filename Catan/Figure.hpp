#pragma once
#include "Component.hpp"

class Figure : public Component {
public:
  std::string to_string() const {
    return type + delimiter + imagePath + delimiter + std::to_string(posX) +
           delimiter + std::to_string(posY) + delimiter +
           std::to_string(worthPoints);
  }

protected:
  double posX, posY;
  int worthPoints;

public:
  Figure();

  string getType() const override { return FIGURE; }
  string getImagePath() override { return ""; }
  void toString() override {}

  virtual int getWorthPoints() const = 0;
};
