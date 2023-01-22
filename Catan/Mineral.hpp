#pragma once
#include "Card.hpp"

class Mineral : public Card {
private:
  const char *name = "Mineral";
  const char *imagePath = "Images/resourcesCards/mineralCard.png";
  int totalCards = 19;

public:
  Mineral();

  const char *getName() const;
  string getImagePath() override { return this->imagePath; }
  int getTotalCards() const;

  void toString() override {
    std::cout << "name: " << this->name << std::endl
              << "imagePath: " << this->imagePath << std::endl
              << "totalCards: " << this->totalCards << std::endl;
  }
};
