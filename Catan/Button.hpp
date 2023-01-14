#pragma once
#include "CImg.h"
#include "Colors.hpp"
#include "Label.hpp"
#include <iostream>
using namespace cimg_library;

#define log(x) std::cout << x << std::endl;

extern CImgDisplay mainDisplay;

class Button : public Label {
private:
  const int offset_x = 100;
  const int offset_y = 50;
  const int text_offset_x = 15;
  const int text_offset_y = 10;

  const unsigned char *primaryColor;
  const unsigned char *secondaryColor;

  CImg<unsigned char> image;

  int mouse_x = mainDisplay.mouse_x(), mouse_y = mainDisplay.mouse_y();

  int top_bound_x = get_x_position(), top_bound_y = get_y_position(),
      bot_bound_x = get_x_position() + offset_x,
      bot_bound_y = get_y_position() + offset_y;

  bool _isPressed;

private:
  bool isMouseOver();
  bool isMouseInTop();
  bool isMouseInBot();

  void changeState();
  void changeColor(const unsigned char *);

  void resizeRectangle();
  int length(const char *);
  int getOffsetX();
  int getOffsetY();

public:
  Button();
  Button(CImg<unsigned char>&, const char *, int, int, unsigned int,
         const unsigned char *);

  void setPressed(bool);
  bool isPressed() const;
};
