#pragma once
#include "Component.hpp"
class Figure : public Component {
public:
  int worthPoints;

public:
  Figure();

  virtual int getWorthPoints() const = 0;
};
