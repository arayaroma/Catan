#pragma once
#include "Component.hpp"
#include <iostream>
#include <string>

class Figure : public Component {
private:
public:
  Figure() { setTypeClass(FIGURE); }
  Figure(std::string, std::string);

  void to_string() {
    std::cout << this->type << " " << this->url << " " << std::endl;
  }
};
