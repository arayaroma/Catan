
#pragma once
#include "Card.hpp"

class Wheat : public Card {
private:
  const char *name = "Wheat";
  const char *imagePath = "Images/resourcesCards/wheatCard.png";
 
public:
  Wheat();

  const char *getName() const;
  string getImagePath() override { return this->imagePath; }
  int getTotalCards() const;

  void toString() override {
      std::cout << "name: " << this->name << std::endl
          << "imagePath: " << this->imagePath << std::endl;
  }
};
