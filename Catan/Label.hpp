#pragma once
#include "CImg.h"
using namespace cimg_library;

class Label {
protected:
  const char *text;
  int x_position, y_position;
  unsigned int font_size;
  const unsigned char *foreground_color;
  int background_color;

public:
  Label();
  Label(CImg<unsigned char> &, const char *, int, int, unsigned int,
        const unsigned char*, const int);

  void set_text(const char *);
  const char *get_text() const;

  const char *const mod_get_text() const;

  void set_x_position(int);
  int get_x_position() const;

  void set_y_position(int);
  int get_y_position() const;

  void set_font_size(unsigned int);
  unsigned int get_font_size() const;
};
