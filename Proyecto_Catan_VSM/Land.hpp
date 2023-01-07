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
  Land() {
    setTypeClass(LAND);
    this->type = "";
    this->url = "";
    this->posx = 0;
    this->posy = 0;
  }

  Land(std::string, std::string, double x, double y);
  Land(Component *) {}

  void setPosx(double x);
  double getPosx();

  void setPosy(double y);
  double getPosy();

  void toString() override {}

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }
  void printImage() override {
    Window window;
    window.Image(this->url);
  }
};
