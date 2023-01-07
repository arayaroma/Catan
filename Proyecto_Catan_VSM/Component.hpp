#pragma once
#include <iostream>
#include <string>
#include "Window.hpp"

#define LAND "Land"
#define FIGURE "Figure"
#define CARD "Card"

class Component {
protected:
  std::string url;
  std::string type;

public:
  std::string typeClass;

public:
  Component();

<<<<<<< HEAD
  virtual void printImage(int x, int y)=0;

=======
>>>>>>> 2cedb8d6aca886621312c34b9843c1109b9bdc86
  void setTypeClass(std::string);
  std::string getTypeClass();

  void setType(std::string);
  std::string getType();

  void setUrl(std::string);
  std::string getUrl();

  virtual void toString() = 0;
  virtual void getClassName() = 0;
  virtual void printImage() = 0;
};
