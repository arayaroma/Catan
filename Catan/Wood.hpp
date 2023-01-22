#pragma once
#include "Card.hpp"

class Wood : public Card {
private:
  string name = "Wood";
  string imagePath = "Images/resourcesCards/woodCard.png";
  int totalCards = 19;

public:
  Wood();

  string getName() const;
  string getImagePath() override { return this->imagePath; }
  int getTotalCards() const;

  void toString() override {
    std::cout << "name: " << this->name << std::endl
              << "imagePath: " << this->imagePath << std::endl
              << "totalCards: " << this->totalCards << std::endl;
  }
};
