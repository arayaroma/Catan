#pragma once
#include "Label.hpp"
class Button : public Label {
private:
  bool _isPressed;

public:
  Button();

  void setPressed(bool);
  bool isPressed() const;
};
