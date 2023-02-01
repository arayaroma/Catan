#pragma once
#include "Figure.hpp"

/*
    60X Roads
    It needs to be shopped:
    1 Clay + 1 Wood

    I.
    A new road always have to be placed from the its player
    roads, towns or cities.

    II.
    In every path, it can only be 1 Road.

    III.
    Whenever a player builds a Path that is at least of 5 Roads,
    (Doesn't count bifurcations), It would get the Special Card:
    Longest Commercial Path, however if another player build a
    longer path that the player who has the special card, it would
    get immediately that card, therefore 2 points.
*/

class Road : public Figure {
public:
  Road();
  Road(string url) { this->imagePath = url; }
  void setPosX(double posX) { this->posX = posX; }
  double getPosX() { return this->posX; }

  void setPosY(double posY) { this->posY = posY; }
  double getPosY() { return this->posY; }

  string getType() const override { return FIGURE; }
  string getImagePath() override { return this->imagePath; }
  void toString() override {}
  int getWorthPoints() const override { return this->worthPoints; }
};
