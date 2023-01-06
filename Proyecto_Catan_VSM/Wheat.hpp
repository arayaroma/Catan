#pragma once
#include "Component.hpp"

/*
    19X Wheat
*/

class Wheat : Component {
private:
public:
  Wheat();
  void toString() override {}

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }
};
