#pragma once
#include "Figure.hpp"
#include <iostream>
#include <string>
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
  const int worthPoint = 1;

private:
    double posx;
    double posy;
public:
   Town();
  Town(std::string, std::string, double x, double y);
  Component *getResource();

  int getWorthPoints() const override { return this->worthPoints; }

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }

  void printImage() override {}

  void printHexagon(int x, int y) override {
      Window::getInstance().printTown(this->url,x,y);
  }

  void toString() override {}
};
