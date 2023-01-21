#pragma once
#include "Card.hpp"

class Clay : public Card {
private:
  const char *name = "Clay";
  const char *imagePath = "Images/resourcesCards/clayCard.png";


public:
  Clay();

  const char *getName() const;
  const char *getImagePath() const;
  
  void toString() override {
    std::cout 
              << "imagePath: " << this->name << std::endl
              << "totalCards: " << this->imagePath << std::endl;
  }
};
