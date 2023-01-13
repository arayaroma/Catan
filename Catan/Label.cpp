#include "Label.hpp"

Label::Label() {
  this->text = "";
  this->x_position = 0;
  this->y_position = 0;
  this->font_size = 12;
}

Label::Label(CImg<unsigned char> &image, const char *text, int x_position,
             int y_position, unsigned int font_size,
             const unsigned char *const foreground_color,
             const int background_color) {
  this->text = text;
  this->x_position = x_position;
  this->y_position = y_position;
  this->font_size = font_size;
  this->foreground_color = foreground_color;
  this->background_color = background_color;

  image.draw_text(this->get_x_position(), this->get_y_position(),
                  this->mod_get_text(), foreground_color, background_color, 1,
                  this->get_font_size());
}

void Label::set_text(const char *text) { this->text = text; }

const char *Label::get_text() const { return this->text; }

const char *const Label::mod_get_text() const {
  const char *const text_c = this->text;
  return text_c;
}

void Label::set_x_position(int x_position) { this->x_position = x_position; }
int Label::get_x_position() const { return x_position; }

void Label::set_y_position(int y_position) { this->y_position = y_position; }
int Label::get_y_position() const { return this->y_position; }

void Label::set_font_size(unsigned int font_size) {
  this->font_size = font_size;
}

unsigned int Label::get_font_size() const { return this->font_size; }
