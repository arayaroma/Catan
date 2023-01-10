#pragma once
#include "Component.hpp"
#include <iostream>

class Land : public Component {
private:
  double posx;
  double posy;

public:
  Land();

  Land(std::string, std::string, double x, double y);

  void setPosx(double x);
  double getPosx();

  void setPosy(double y);
  double getPosy();

  void toString() override { std::cout << posx << " " << posy << std::endl; }

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }
  void printImage() override {}
};
