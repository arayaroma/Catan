#pragma once
#include <string>

#define FIGURE "Figure"
#define CARD "Card"
#define LAND "Land"
#define DICE "Dice"

using std::string;
class Component {
  friend class Game;

protected:
  string type;
  string imagePath;

public:
  Component(const Component&) = delete;

  virtual void getType() = 0;
  virtual void printImage() = 0;
  virtual void toString() = 0;
};
