#include "Program.hpp"
using namespace std;

const unsigned char WHITE[] = {255, 255, 255};
const unsigned char BLACK[] = {0, 0, 0};
const int transparent = 0;
const float opacity = 1;

const char *catan_window_title = "Catan - Title Screen";
const char *const image_path = "images/catan_1280x720.jpg";
unsigned int catan_title_display_width = 1280, catan_title_display_height = 720;
CImg<unsigned char> image(image_path);
CImgDisplay title_display(catan_title_display_width, catan_title_display_height,
                          catan_window_title, 3, false, false);

Label *catan = new Label("Catan", 490, 50, 128);
Label *playLabel = new Label("Jugar", 490, 250, 128);
Label *about = new Label("Acerca de", 490, 450, 128);

Program::Program() {
  this->turn = 0;
  lands = LinkedList();
}
void Program::assemblyLand() {
  for (int i = 0; i < 4; i++) {
    lands.add(new Land("Grass", "Images/tiles/Grass.png"));
    lands.add(new Land("Forest", "Images/tiles/Forest.png"));
    if (i < 3) {
      lands.add(new Land("Brick", "Images/tiles/Brick.png"));
      lands.add(new Land("Mountain", "Images/tiles/Mountain.png"));
      lands.add(new Land("Field", "Images/tiles/Field.png"));
    }
  }
  lands.add(new Land("Dessert", "Images/tiles/Dessert.png"));
  lands.to_string();
}

void Program::printTitleScreenLabels() {

  CImgDisplay title_display(catan_title_display_width,
                            catan_title_display_height, catan_window_title, 3,
                            false, false);

  image.draw_text(catan->get_x_position(), catan->get_y_position(),
                  catan->mod_get_text(), BLACK, transparent, opacity,
                  catan->get_font_size());

  image.draw_text(playLabel->get_x_position(), playLabel->get_y_position(),
                  playLabel->mod_get_text(), BLACK, transparent, opacity,
                  playLabel->get_font_size());

  image.draw_text(about->get_x_position(), about->get_y_position(),
                  about->mod_get_text(), BLACK, transparent, opacity,
                  about->get_font_size());
}

void Program::showDisplay() {
  while (!title_display.is_closed()) {
    title_display.display(image);
    if (title_display.button() && title_display.mouse_x() < 100 &&
        title_display.mouse_y() < 100) {
      cout << "1" << endl;
    }
  }
}