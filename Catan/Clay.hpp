#pragma once
#include "Card.hpp"

class Clay : public Card {
private:
  const char *name = "Clay";
  const char *imagePath = "Images/resourcesCards/clayCard.png";
  int totalCards = 19;

public:
  Clay();

  const char *getName() const;
  const char *getImagePath() const;
  int getTotalCards() const;

  void toString() override {
    std::cout << "name: " << this->totalCards << std::endl
              << "imagePath: " << this->name << std::endl
              << "totalCards: " << this->imagePath << std::endl;
  }
};
