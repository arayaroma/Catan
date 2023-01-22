#pragma once
#include "Card.hpp"
using std::string;

class Clay : public Card {
private:
  const char *name = "Clay";
  const char *imagePath = "Images/resourcesCards/clayCard.png";
  int totalCards = 19;

public:
  Clay();

  const char *getName() const;
  string getImagePath() override { return "Images/resourcesCards/clayCard.png"; }
  string getType() const override{ return CARD; }
  int getTotalCards() const;

  void toString() override {
    std::cout << "name: " << this->totalCards << std::endl
              << "imagePath: " << this->name << std::endl
              << "totalCards: " << this->imagePath << std::endl;
  }
};
