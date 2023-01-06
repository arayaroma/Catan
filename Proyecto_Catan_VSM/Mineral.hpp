#pragma once
#include "Component.hpp"

/*
    19X Mineral
*/

class Mineral : public Component {
private:
public:
  Mineral();
  void toString() override {}

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }
};
