#pragma once
#include "Component.hpp"

/*
    19X Wood
*/

class Wood : Component {
private:
public:
  Wood();
  void toString() override {}

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }
};
