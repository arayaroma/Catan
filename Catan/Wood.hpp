#pragma once
#include "Card.hpp"

class Wood : public Card {
private:
  const char *name = "Wood";
  const char *imagePath = "Images/resourcesCards/woodCard.png";
  int totalCards = 19;

public:
  Wood();

  const char *getName() const;
  const char *getImagePath() const;
  int getTotalCards() const;

  void toString() override {
    std::cout << "name: " << this->name << std::endl
              << "imagePath: " << this->imagePath << std::endl
              << "totalCards: " << this->totalCards << std::endl;
  }
};
