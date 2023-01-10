#pragma once
class Figure {
public:
  int worthPoints;

public:
  Figure();

  virtual int getWorthPoints() const = 0;
};
