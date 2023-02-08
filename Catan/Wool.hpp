#pragma once
#include "Card.hpp"

class Wool : public Card {
public:
  std::string to_string() const {
    return type + delimiter + imagePath + delimiter + name + delimiter;
  }

private:
  const char *name = "Wool";
  const char *imagePath = "Images/resourcesCards/woolCard.png";

public:
  Wool();

  const char *getName() const;
  string getImagePath() override { return this->imagePath; }
  int getTotalCards() const;

  void toString() override {
    std::cout << "name: " << this->name << std::endl
              << "imagePath: " << this->imagePath << std::endl;
  }
};
