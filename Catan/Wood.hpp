#pragma once
#include "Card.hpp"

class Wood : public Card {
public:
  std::string to_string() const {
    return type + delimiter + imagePath + delimiter + name + delimiter;
  }

private:
  const char *name = "Wood";
  const char *imagePath = "Images/resourcesCards/woodCard.png";

public:
  Wood();

  const char *getName() const;
  const char *getImagePath() const;

  void toString() override {
    std::cout << "name: " << this->name << std::endl
              << "imagePath: " << this->imagePath << std::endl;
  }
};
