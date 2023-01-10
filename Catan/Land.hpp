#pragma once
#include "Component.hpp"
#include "Window.hpp"

class Land : public Component {
private:
  std::string type;
  std::string url;
  double posx;
  double posy;

public:
  Land();

  Land(std::string, std::string, double x, double y);
  Land(Component *) {}

  void setPosx(double x);
  double getPosx();

  void setPosy(double y);
  double getPosy();

  void toString() override {
      std::cout << posx <<" "<<posy<< std::endl;
  }

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }
  void printHexagon(int x, int y) override {
      this->posx = x;
      this->posy = y;
      
    Window::getInstance().printHexagon(this->url, x, y);
  }

  void printImage() override {}
};
