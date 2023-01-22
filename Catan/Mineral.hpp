#pragma once
#include "Card.hpp"

class Mineral : public Card {
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
