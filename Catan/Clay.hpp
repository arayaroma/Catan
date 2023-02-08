#pragma once
#include "Card.hpp"
using std::string;

class Clay : public Card {
public:
  std::string to_string() const {
    return type + delimiter + imagePath + delimiter + name + delimiter;
  }

private:
  const char *name = "Clay";
  const char *imagePath = "Images/resourcesCards/clayCard.png";

public:
  Clay();

  const char *getName() const;
  const char *getImagePath() const;

  void toString() override {
    std::cout << "imagePath: " << this->name << std::endl
              << "totalCards: " << this->imagePath << std::endl;
  }
};
