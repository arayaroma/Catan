#pragma once

#include "Component.hpp"
#include <iostream>
#include <string>

class Land : public Component {
private:
  std::string type;
  std::string url;
  /*std::string owner;
  std::string name;*/

public:
  Land() {
    setTypeClass(LAND);
    this->type = "";
    this->url = "";
  }

  Land(std::string, std::string);
  Land(Component *) {}

  void to_string() {
    std::cout << this->type << "   " << this->url << " " << std::endl;
  }
};
