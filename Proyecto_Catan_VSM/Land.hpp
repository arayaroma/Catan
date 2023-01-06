#pragma once

#include "Component.hpp"
#include <iostream>
#include <string>

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

  void to_string() {
    std::cout << this->type << " " << this->url << " "<< posx<<" "<<posy<< std::endl;
  }
};
