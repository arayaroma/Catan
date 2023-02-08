#pragma once
#include "Card.hpp"

class Mineral : public Card {
public:
  std::string to_string() const {
    return type + delimiter + imagePath + delimiter + name + delimiter;
  }

private:
  const char *name = "Mineral";
  const char *imagePath = "Images/resourcesCards/mineralCard.png";

public:
  Mineral();

  const char *getName() const;
  string getImagePath() override { return this->imagePath; }

  void toString() override {
    std::cout << "name: " << this->name << std::endl
              << "imagePath: " << this->imagePath << std::endl;
  }
};
