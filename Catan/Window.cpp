#include "Window.hpp"
const unsigned char WHITE[] = {255, 255, 255};
const unsigned char BLACK[] = {0, 0, 0};
const int transparent = 0;
const float opacity = 1;

const char *catan_window_title = "Catan - Title Screen";
const char *const image_path = "Images/catan_1280x720.jpg";
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
}

void Window::showDisplay() {
  while (!title_display.is_closed()) {
    title_display.display(image);
    title_display.wait();
    mouseFunction();
  }
}

void Window::mouseFunction() {
  if (title_display.button() && title_display.mouse_x() < 100 &&
      title_display.mouse_y() < 100) {
    std::cout << "isClicked" << std::endl;
    printBoard();
    showGameDisplay();
  }
}

void Window::printHexagon(std::string url, int x, int y) {
  const char *const img = url.c_str();
  CImg<unsigned char> imageHexa(img);
  image2.draw_image(x, y, imageHexa);
}

void Window::showGameDisplay() {
  CImgDisplay game_title_display(catan_title_display_width,
                                 catan_title_display_height, catan_window_title,
                                 3, false, false);
  title_display.close();
  while (!game_title_display.is_closed()) {
    game_title_display.wait();
    game_title_display.display(image2);
  }
}

void Window::printBoard() {
  int top_height = 10; // primera,segunda,tercera
  int bot_height = 10; // ultima y penultima columna de hexagonos
  int cycle_cord_x = 0;

  DataStructures dataStructures;
  dataStructures.loadLands();
  Node<Land> *temp = dataStructures.lands.head;
  std::string tempUrl = temp->getData().getUrl();
  std::cout << temp->getData().getUrl();

  bot_height += 295;
  for (cycle_cord_x = 470; cycle_cord_x <= 620; cycle_cord_x += 75) {

    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, top_height);
    temp = temp->getNext();

    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, bot_height);
    temp = temp->getNext();
  }

  top_height += 75;
  bot_height = 230;
  for (cycle_cord_x = 435; cycle_cord_x <= 695; cycle_cord_x += 75) {

    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, top_height);
    temp = temp->getNext();

    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, bot_height);
    temp = temp->getNext();
  }

  top_height += 75;
  for (cycle_cord_x = 400; cycle_cord_x <= 700; cycle_cord_x += 75) {

    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, top_height);
    temp = temp->getNext();
  }
}

void Window::Image(std::string url) {}