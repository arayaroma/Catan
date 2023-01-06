#pragma once
#include "Component.hpp"

/*
    19X Wool
*/

class Wool : public Component {
private:
public:
  Wool();
  void toString() override {}

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }
};
