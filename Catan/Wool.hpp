#pragma once
#include "Card.hpp"

class Wool : public Card {
private:
  const char *name = "Wool";
  const char *imagePath = "Images/resourcesCards/woolCard.png";
  int totalCards = 19;

public:
  Wool();

  const char *getName() const;
  string getImagePath() override { return this->imagePath; }
  int getTotalCards() const;

  void toString() override {
    std::cout << "name: " << this->name << std::endl
              << "imagePath: " << this->imagePath << std::endl
              << "totalCards: " << this->totalCards << std::endl;
  }
};
