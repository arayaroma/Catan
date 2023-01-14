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

  resizeRectangle();

  image.draw_rectangle(x_position, y_position, x_position + getOffsetX(),
                       y_position + offset_y, primaryColor, opacity);
  Label *_text =
      new Label(image, text, x_position + text_offset_x,
                y_position + text_offset_y, font_size, WHITE, transparent);
}

int Button::getOffsetX() {
  if (length(this->text) == 1)
    return length(this->text) * 50;
  if (length(this->text) < 10)
    return length(this->text) * 18 + 5;
  return length(this->text) * 13 + 15;
}

int Button::length(const char *array) {
  std::size_t Size = strlen(array);
  return Size;
}

void Button::resizeRectangle() { log("size: " << length(this->text)); }

void Button::setPressed(bool isPressed) { this->_isPressed = isPressed; }
bool Button::isPressed() const {
  while (!mainDisplay.is_closed()) {
    if (mainDisplay.button() & 1) {
      mainDisplay.wait();
      log("Pressed");
      return true;
    }
  }
  return false;
}

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