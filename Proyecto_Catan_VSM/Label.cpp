#include "Label.hpp"

Label::Label() {
  this->text = "";
  this->x_position = 0;
  this->y_position = 0;
  this->font_size = 12;
}

Label::Label(const char *text, int x_position, int y_position,
             unsigned int font_size) {
  this->text = text;
  this->x_position = x_position;
  this->y_position = y_position;
  this->font_size = font_size;
}

void Label::set_text(const char *text) { this->text = text; }

const char *Label::get_text() { return this->text; }

const char *const Label::mod_get_text() {
  const char *const text_c = this->text;
  return text_c;
}

void Label::set_x_position(int x_position) { this->x_position = x_position; }
int Label::get_x_position() { return x_position; }

void Label::set_y_position(int y_position) { this->y_position = y_position; }
int Label::get_y_position() { return this->y_position; }

void Label::set_font_size(unsigned int font_size) {
  this->font_size = font_size;
}

unsigned int Label::get_font_size() { return this->font_size; }
