#include "Program.h"
#include "CImg.h"
#include <iostream>
#include <string>
#include "Label.h"

using namespace cimg_library;
using namespace std;

const unsigned char WHITE[] = { 255, 255, 255 };
const unsigned char BLACK[] = { 0, 0, 0 };

const int transparent = 0;
const float opacity = 1;

// Global Scope
const char* const image_path = "images/catan_1280x720.jpg";
const char* catan_window_title = "Catan - Title Screen";
unsigned int catan_title_display_width = 1280, catan_title_display_height = 720;

CImg<unsigned char> image(image_path);
CImgDisplay title_display(catan_title_display_width,
	catan_title_display_height, catan_window_title, 3, false, false);

Label* catan = new Label("Catan", 490, 50, 128);
Label* play = new Label("Jugar", 490, 250, 128);
Label* about = new Label("Acerca de", 490, 450, 128);


int main() {

	image.draw_text(catan->get_x_position(), catan->get_y_position()
		, catan->mod_get_text(), BLACK,
		transparent, opacity, catan->get_font_size());

	image.draw_text(play->get_x_position(), play->get_y_position()
		, play->mod_get_text(), BLACK,
		transparent, opacity, play->get_font_size());

	image.draw_text(about->get_x_position(), about->get_y_position()
		, about->mod_get_text(), BLACK,
		transparent, opacity, about->get_font_size());


	while (!title_display.is_closed()) {
		title_display.display(image);
		if (title_display.button() &&
			title_display.mouse_x() < 100 &&
			title_display.mouse_y() < 100) {
			cout << "1" << endl;
		}
	}

	return 0;
}
