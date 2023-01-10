#pragma once
#include <string>

#define LAND "Land"
#define FIGURE "Figure"
#define CARD "Card"

class Component {
  friend class Game;

protected:
  std::string url;
  std::string type;

public:
  std::string typeClass;

public:
  Component();

  void setTypeClass(std::string);
  std::string getTypeClass();

  void setType(std::string);
  std::string getType();

  void setUrl(std::string);
  std::string getUrl();

  virtual void getClassName() = 0;
  virtual void printImage() = 0;
  virtual void toString() = 0;
};
