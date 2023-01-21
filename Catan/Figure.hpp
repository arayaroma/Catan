#pragma once
#include "Component.hpp"

class Figure : public Component {
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
