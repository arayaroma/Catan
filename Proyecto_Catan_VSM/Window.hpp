#pragma once
#include "CImg.h"
#include "Label.hpp"
#include <iostream>
using namespace cimg_library;

extern const unsigned char WHITE[3];
extern const unsigned char BLACK[3];
extern const int transparent;
extern const float opacity;

extern const char *catan_window_title;
extern const char *const image_path;
extern unsigned int catan_title_display_width, catan_title_display_height;

extern Label *catan;
extern Label *playLabel;
extern Label *about;

 
extern const char* const img; 


class Window {

private:
public:
	void printTitleScreenLabels();
	void showDisplay();
	void showGameDisplay();
	 void printHexagon(std::string, int x, int y);
	 void Image(std::string);
};
