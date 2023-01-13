#include "Button.hpp"

Button::Button() {}

Button::Button(CImg<unsigned char> &image, const char *text, int x_position,
               int y_position, unsigned int font_size,
               const unsigned char *color) {
  this->text = text;
  this->x_position = x_position;
  this->y_position = y_position;
  this->font_size = font_size;
  this->primaryColor = color;
  this->image = image;

  const float opacity = 1;

  image.draw_rectangle(x_position, y_position, x_position + offset_x,
                       y_position + offset_y, color, opacity);

  Label *_text =
      new Label(image, text, x_position + text_offset_x,
                y_position + text_offset_y, font_size, WHITE, transparent);
}

void Button::setPressed(bool isPressed) { this->_isPressed = isPressed; }
bool Button::isPressed() const { return this->_isPressed; }

bool Button::isMouseOver() {
  if (isMouseInTop() && isMouseInBot())
    return true;
  return false;
}

bool Button::isMouseInTop() {
  if (mouse_x > top_bound_x && mouse_y > top_bound_y)
    return true;
  return false;
}

bool Button::isMouseInBot() {
  if (mouse_x < bot_bound_x && mouse_y < bot_bound_y)
    return true;
  return false;
}

void Button::changeColor(const unsigned char *color) {
  image.draw_rectangle(x_position, y_position, x_position + offset_x,
                       y_position + offset_y, color, 1);

  Label *_text =
      new Label(image, text, x_position + text_offset_x,
                y_position + text_offset_y, font_size, WHITE, transparent);
}

void Button::changeState() {
  if (isMouseOver())
    changeColor(WHITE);
}