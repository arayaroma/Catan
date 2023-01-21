#pragma once
#include "Card.hpp"

class Wool : public Card {
private:
  const char *name = "Wool";
  const char *imagePath = "Images/resourcesCards/woolCard.png";
  
public:
  Wool();

  const char *getName() const;
  const char *getImagePath() const;
  int getTotalCards() const;

  void toString() override {
      std::cout << "name: " << this->name << std::endl
          << "imagePath: " << this->imagePath << std::endl;
             
  }
};
