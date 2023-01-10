#pragma once
#include <iostream>
class Figure {
protected:
  std::string type, url;
  double posx, posy;
  int worthPoints;

public:
  Figure();

  virtual int getWorthPoints() const = 0;

};
