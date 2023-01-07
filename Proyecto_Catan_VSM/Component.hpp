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

  virtual void printHexagon(int x, int y)=0;

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
