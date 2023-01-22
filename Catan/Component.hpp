#pragma once
#include <iostream>
#include <string>

#define FIGURE "Figure"
#define CARD "Card"
#define LAND "Land"
#define DICE "Dice"

using std::string;
class Component {
protected:
  string type;
  string imagePath;

public:
  Component() {
    this->type = "";
    this->imagePath = "";
  }

  virtual string getType() const = 0;
  virtual string getImagePath() = 0;
  virtual void toString() = 0;
};
