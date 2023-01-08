#pragma once
#include "Component.hpp"

class Clay : public Component {
private:
  const char *name = "Clay";
  const char *imagePath = "Images/resourcesCards/clayCard.png";
  const int totalCards = 19;

public:
  Clay();

  const char *getName() const;
  const char *getImagePath() const;
  const int getTotalCards() const;

  void toString() override {
    std::cout << "name: " << this->totalCards << std::endl
              << "imagePath: " << this->name << std::endl
              << "totalCards: " << this->imagePath << std::endl;
  }

  void printImage() override { Window::getInstance().Image(this->imagePath); }

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }
};
