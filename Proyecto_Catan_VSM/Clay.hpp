#pragma once
#include "Component.hpp"

/*
    19X Clay
*/

class Clay : public Component {
private:
public:
  Clay();
  void toString() override {}

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }
};
