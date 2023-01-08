#pragma once
#include "Component.hpp"

class Wool : public Component {
private:
  const char *name = "Wool";
  const char *imagePath = "Images/resourcesCards/woolCard.png";
  const int totalCards = 19;

public:
  Wool();

  const char *getName() const;
  const char *getImagePath() const;
  const int getTotalCards() const;

  void toString() override {
    std::cout << "name: " << this->name << std::endl
              << "imagePath: " << this->imagePath << std::endl
              << "totalCards: " << this->totalCards << std::endl;
  }

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }
  void printImage() override { Window::getInstance().Image(this->imagePath); }

  void printHexagon(int x, int y) override {}
};
