#pragma once

class Label {
private:
  const char *text;
  int x_position, y_position;
  unsigned int font_size;

public:
  Label();
  Label(const char *, int, int, unsigned int);

  void set_text(const char *);
  const char *get_text();

  const char *const mod_get_text();

  void set_x_position(int);
  int get_x_position();

  void set_y_position(int);
  int get_y_position();

  void set_font_size(unsigned int);
  unsigned int get_font_size();
};
