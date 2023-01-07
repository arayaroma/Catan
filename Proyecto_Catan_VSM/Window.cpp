#include "Window.hpp"
const unsigned char WHITE[] = {255, 255, 255};
const unsigned char BLACK[] = {0, 0, 0};
const int transparent = 0;
const float opacity = 1;

const char *catan_window_title = "Catan - Title Screen";
const char *const image_path = "images/catan_1280x720.jpg";
unsigned int catan_title_display_width = 1280, catan_title_display_height = 720;
CImg<unsigned char> image(image_path);
CImg<unsigned char> image2(image_path);
CImgDisplay title_display(catan_title_display_width, catan_title_display_height,
                          catan_window_title, 3, false, false);

Label *catan = new Label("Catan", 490, 50, 128);
Label *playLabel = new Label("Jugar", 490, 250, 128);
Label *about = new Label("Acerca de", 490, 450, 128);

void Window::printTitleScreenLabels() {

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

<<<<<<< HEAD

}
=======
*/
}

void Window::loadImages() {}

>>>>>>> 2cedb8d6aca886621312c34b9843c1109b9bdc86
void Window::showDisplay() {
  while (!title_display.is_closed()) {
    title_display.display(image);
    title_display.wait();
    if (title_display.button() && title_display.mouse_x() < 100 &&
        title_display.mouse_y() < 100) {
      std::cout << "1" << std::endl;
      showGameDisplay();
    }
  }
}
<<<<<<< HEAD
void Window::printHexagon(std::string url, int x, int y) {
    const char* const img = url.c_str();
    CImg <unsigned char>imageHexa(img);
    image2.draw_image(x, y, imageHexa);
}

void Window::showGameDisplay() {
    CImgDisplay game_title_display(catan_title_display_width, catan_title_display_height,
        catan_window_title, 3, false, false);
    title_display.close();
    while (!game_title_display.is_closed()) {
        game_title_display.wait();
        game_title_display.display(image2);
    }  
=======

void Window::Image(std::string url) {

  const char *const img = url.c_str();
  CImg<unsigned char> image2(img);

  int Qry1 = 325;
  int Qry2 = 350;
  int Qry3 = 375;

  int x = 545, y = 325;

  for (int i = 0; i < 3; i++) {

    image.draw_image(545, Qry2, image2);
    image.draw_line(575, Qry1, 545, Qry1, BLACK, 1);
    image.draw_line(575, Qry3, 545, Qry3, BLACK, 1);
    image.draw_line(545, Qry3, 530, Qry2, BLACK, 1);
    image.draw_line(530, Qry2, 545, Qry1, BLACK, 1);
    image.draw_line(575, Qry1, 590, Qry2, BLACK, 1);
    image.draw_line(575, Qry3, 590, Qry2, BLACK, 1);

    Qry1 = Qry1 + 50;
    Qry2 = Qry2 + 50;
    Qry3 = Qry3 + 50;
  }
  // Segunda fila de hexagonos
  Qry1 = 300;
  Qry2 = 325;
  Qry3 = 350;
  for (int i = 0; i < 4; i++) {
    image.draw_image(590, Qry2, image2);

    image.draw_line(620, Qry1, 590, Qry1, BLACK, 1);
    image.draw_line(620, Qry3, 590, Qry3, BLACK, 1);
    image.draw_line(635, Qry2, 620, Qry3, BLACK, 1);
    image.draw_line(590, Qry3, 575, Qry2, BLACK, 1);
    image.draw_line(575, Qry2, 590, Qry1, BLACK, 1);
    image.draw_line(620, Qry1, 635, Qry2, BLACK, 1);

    Qry1 = Qry1 + 50;
    Qry2 = Qry2 + 50;
    Qry3 = Qry3 + 50;
  }
  Qry1 = 275;
  Qry2 = 300;
  Qry3 = 325;

  for (int i = 0; i < 5; i++) {
    image.draw_image(635, Qry2, image2);
    image.draw_line(635, Qry1, 665, Qry1, BLACK, 1); // techo lad 1
    image.draw_line(665, Qry1, 680, Qry2, BLACK, 1); // lado der arr
    image.draw_line(680, Qry2, 665, Qry3, BLACK, 1); // lado der abaj
    image.draw_line(635, Qry3, 665, Qry3, BLACK, 1); // piso
    image.draw_line(635, Qry3, 620, Qry2, BLACK, 1); // lado isq aba
    image.draw_line(635, Qry1, 620, Qry2, BLACK, 1); // lado isq arri

    Qry1 = Qry1 + 50;
    Qry2 = Qry2 + 50;
    Qry3 = Qry3 + 50;
  }
  Qry1 = 300;
  Qry2 = 325;
  Qry3 = 350;
  for (int i = 0; i < 4; i++) {
    image.draw_image(680, Qry2, image2);
    image.draw_line(680, Qry1, 665, Qry2, BLACK, 1); // lado isq arr
    image.draw_line(665, Qry2, 680, Qry3, BLACK, 1); // lado isq abaj
    image.draw_line(680, Qry1, 710, Qry1, BLACK, 1); // techo
    image.draw_line(710, Qry1, 725, Qry2, BLACK, 1); // der arri
    image.draw_line(725, Qry2, 710, Qry3, BLACK, 1); // der abajo
    image.draw_line(710, Qry3, 680, Qry3, BLACK, 1); // piso

    Qry1 = Qry1 + 50;
    Qry2 = Qry2 + 50;
    Qry3 = Qry3 + 50;
  }
  // tercera fila de hexagonos
  Qry1 = 325;
  Qry2 = 350;
  Qry3 = 375;
  for (int i = 0; i < 3; i++) {
    image.draw_image(725, Qry2, image2);
    image.draw_line(725, Qry1, 710, Qry2, BLACK, 1); // der arriba
    image.draw_line(710, Qry2, 725, Qry3, BLACK, 1); // der abajo
    image.draw_line(725, Qry1, 755, Qry1, BLACK, 1); // techo
    image.draw_line(755, Qry1, 770, Qry2, BLACK, 1); // isq arri
    image.draw_line(770, Qry2, 755, Qry3, BLACK, 1); // isq abaj
    image.draw_line(755, Qry3, 725, Qry3, BLACK, 1); // piso

    Qry1 = Qry1 + 50;
    Qry2 = Qry2 + 50;
    Qry3 = Qry3 + 50;
  }
>>>>>>> 2cedb8d6aca886621312c34b9843c1109b9bdc86
}