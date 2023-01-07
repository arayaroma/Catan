#pragma once
#include "Component.hpp"

class Wood : public Component {
private:
  const char *name = "Wood";
  const char *imagePath = "Images/resourcesCards/woodCard.png";
  const int totalCards = 19;

public:
  Wood();

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
  void printImage() override {
    Window window;
    window.Image(this->imagePath);
  }
};
