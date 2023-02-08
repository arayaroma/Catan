#pragma once
#include "Figure.hpp"
#define TOWN "Town"
/*
    20x Towns
    It needs to be shopped:
    1 Clay + 1 Wood + 1 Wool + 1 Wheat

    I.
    Distance rule:
    It only can be created in a vertex,
    if the three vertex around aren't ocuppied by towns,
    no matter the town player.

    II.
    The town has to part from one of the player's road,
    obligatorily.

    III.
    For every town, it owner get resources from the
    bordering, 1 resource_card, whenever the dice indicates.

    IV.
    Every town worth 1 point.!
*/

class Town : public Figure {
public:
  std::string to_string() const {
    return type + delimiter + imagePath + delimiter + std::to_string(posX) +
           delimiter + std::to_string(posY) + delimiter +
           std::to_string(worthPoints);
  }

public:
  Town();
  Town(string url) { this->imagePath = url; }
  void setPosX(double posX) { this->posX = posX; }
  double getPosX() { return this->posX; }

  void setPosY(double posY) { this->posY = posY; }
  double getPosY() { return this->posY; }

  int getWorthPoints() const override { return this->worthPoints; }
  string getType() const override { return FIGURE; }
  string getImagePath() override { return this->imagePath; }
  void toString() override {}
};
