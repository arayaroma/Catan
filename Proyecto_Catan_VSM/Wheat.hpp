
#pragma once
#include "Component.hpp"

class Wheat : public  Component {
private:
  const char *name = "Wheat";
  const char *imagePath = "Images/resourcesCards/wheatCard.png";
  const int totalCards = 19;

public:
  Wheat();

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
