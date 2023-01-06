#pragma once
#include "Component.hpp"

/*
    16X Cities
    It needs to be shopped:
    3 Stone + 2 Wheat

    I.
    A new city can only be done by an ampliation of a town.

    II.
    If a player get a city, it has to retire the town figure to
    it's reserve, replacing it for the city.

    III.
    For every city, the player gets the double of resources of the
    surrounding tiles, 2 resources_cards, whenever the dice dictate.

    IV.
    Every city worths 2 points.
*/

class City : public Component {
public:
  void toString() override {}

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }
};
