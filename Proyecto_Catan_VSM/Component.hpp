#pragma once
#include <iostream>
#include <string>

#define LAND "Land"
#define FIGURE "Figure"
#define CARD "Card"

class Component {
protected:
  std::string url;
  std::string type;

public:
  std::string typeClass;

  Component();

  void setTypeClass(std::string);
  std::string getTypeClass();

  void setType(std::string);
  std::string getType();

  void setUrl(std::string);
  std::string getUrl();

  virtual void to_string() = 0;
};
