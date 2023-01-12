#include "Window.hpp"

const unsigned char WHITE[] = {255, 255, 255};
const unsigned char BLUEGREEN[] = {0, 170, 255};
const unsigned char ORANGE[] = {255, 140, 0};
const unsigned char BLACK[] = {0, 0, 0};
const int transparent = 0;
const float opacity = 1;

const char *catan_window_title = "Catan - Title Screen";
const char *const image_info = "Images/acercaDe.jpg";
const char *const image_path = "Images/catan_1280x720.jpg";
const char *const image_path_table = "Images/extraCards/pricingTable.jpeg";
const char *const info_game_path = "Images/acercaDe.jpg";
unsigned int catan_title_display_width = 1280, catan_title_display_height = 720;

CImg<unsigned char> image(image_path);
CImg<unsigned char> image2(image_path);
CImg<unsigned char> image3(image_info);

CImg<unsigned char> pricingTable(image_path_table);
CImg<unsigned char> info_game_display(info_game_path);

CImgDisplay titleDisplay(catan_title_display_width, catan_title_display_height,
                         catan_window_title, 3, false, true);

CImgDisplay gameDisplay(catan_title_display_width, catan_title_display_height,
                        catan_window_title, 3, false, true);

CImgDisplay aboutDisplay(catan_title_display_width, catan_title_display_height,
                         catan_window_title, 3, false, true);

Label *catan = new Label("Catan", 490, 50, 128);
Label *playLabel = new Label("Jugar", 515, 250, 128);
Label *about = new Label("Acerca de", 400, 450, 128);
Label *princingTable = new Label("Pricing Table", 0, 1, 20);
Label *materialCard = new Label("Material Card", 0, 215, 20);
Label *developCard = new Label("Develop Card", 0, 320, 20);
Label *returnWindow = new Label("<--", 0, 10, 20);

bool Window::isLeftClicked(CImgDisplay &display) {
  while (!display.is_closed()) {
    if (display.button() & 1) {
      std::cout << "Entra" << std::endl;
      display.wait();
      return true;
    }
  }
  return false;
}

void Window::printTitleScreenLabels() {
  image.draw_text(catan->get_x_position(), catan->get_y_position(),
                  catan->mod_get_text(), ORANGE, transparent, opacity,
                  catan->get_font_size());

  image.draw_text(playLabel->get_x_position(), playLabel->get_y_position(),
                  playLabel->mod_get_text(), ORANGE, transparent, opacity,
                  playLabel->get_font_size());

  image.draw_text(about->get_x_position(), about->get_y_position(),
                  about->mod_get_text(), ORANGE, transparent, opacity,
                  about->get_font_size());
}

bool Window::isBackClicked() {
  if (isLeftClicked(aboutDisplay) &&
      clickAboutLabel(aboutDisplay.mouse_x(), aboutDisplay.mouse_y(),
                      returnWindow)) {
    return true;
  }
  return false;
}

bool Window::isPlayClicked() {
  if (isLeftClicked(titleDisplay) &&
      clickAboutLabel(titleDisplay.mouse_x(), titleDisplay.mouse_y(),
                      playLabel)) {
    return true;
  }
  return false;
}

void Window::goPlayView() {
  FlowController::getInstance().close();
  loadPlayDisplay();
  FlowController::getInstance().goView(gameDisplay, image2);
}

void Window::loadPlayDisplay() {
  image2.draw_image(0, 20, pricingTable);
  image2.draw_text(princingTable->get_x_position(),
                   princingTable->get_y_position(),
                   princingTable->mod_get_text(), ORANGE, transparent, opacity,
                   princingTable->get_font_size());
  image2.draw_text(materialCard->get_x_position(),
                   materialCard->get_y_position(), materialCard->mod_get_text(),
                   ORANGE, transparent, opacity, materialCard->get_font_size());
  printBoard();
  printMaterialCard();
}

bool Window::isAboutClicked() {
  if (isLeftClicked(titleDisplay) &&
      clickAboutLabel(titleDisplay.mouse_x(), titleDisplay.mouse_y(), about)) {
    return true;
  }
  return false;
}

void Window::goAboutView() {
  FlowController::getInstance().close();
  loadAboutDisplay();
  FlowController::getInstance().goView(aboutDisplay, image3);
}

void Window::loadAboutDisplay() {
  image3.draw_text(returnWindow->get_x_position(),
                   returnWindow->get_y_position(), returnWindow->mod_get_text(),
                   ORANGE, transparent, opacity, returnWindow->get_font_size());
}

bool Window::clickAboutLabel(double x, double y, Label *label) {
  if (x > label->get_x_position() && x < label->get_x_position() + 245 &&
      y > label->get_y_position() && y < label->get_y_position() + 245)
    return true;
  return false;
}

void Window::goBackTitle() {
  FlowController::getInstance().close();
  FlowController::getInstance().goView(titleDisplay, image);
}

void Window::printHexagon(std::string url, int x, int y) {
  const char *const img = url.c_str();
  CImg<unsigned char> imageHexa(img);
  image2.draw_image(x, y, imageHexa);
}

void Window::printBoard() {
  int top_height = 10; // primera,segunda,tercera
  int bot_height = 10; // ultima y penultima columna de hexagonos
  int cycle_cord_x = 0;

  DataStructures dataStructures;
  dataStructures.loadLands();
  Node<Land> *temp = dataStructures.lands.head;
  std::cout << temp->getData().getUrl();

  bot_height += 295;
  for (cycle_cord_x = 470; cycle_cord_x <= 620; cycle_cord_x += 75) {
    std::string tempUrl = temp->getData().getUrl();

    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, top_height);
    temp = temp->getNext();
    tempUrl = temp->getData().getUrl();

    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, bot_height);
    temp = temp->getNext();
  }

  top_height += 75;
  bot_height = 230;
  for (cycle_cord_x = 435; cycle_cord_x <= 695; cycle_cord_x += 75) {
    std::string tempUrl = temp->getData().getUrl();
    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, top_height);
    temp = temp->getNext();
    tempUrl = temp->getData().getUrl();

    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, bot_height);
    temp = temp->getNext();
  }

  top_height += 75;
  for (cycle_cord_x = 400; cycle_cord_x <= 700; cycle_cord_x += 75) {
    std::string tempUrl = temp->getData().getUrl();

    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, top_height);
    temp = temp->getNext();
  }
}

void Window::printMaterialCard() {
  ///////MATERIAL CARD IMAGE/////////
  CImg<unsigned char> image_clay("Images/resourcesCards/clayCard.png");
  CImg<unsigned char> image_mineral("Images/resourcesCards/mineralCard.png");
  CImg<unsigned char> image_wheat("Images/resourcesCards/wheatCard.png");
  CImg<unsigned char> image_wood("Images/resourcesCards/woodCard.png");
  CImg<unsigned char> image_wool("Images/resourcesCards/woolCard.png");
  CImg<unsigned char> image_develop(
      "Images/extraCards/progressCardBackwards.png");

  image2.draw_image(0, 240, image_clay);
  image2.draw_image(70, 240, image_mineral);
  image2.draw_image(140, 240, image_wheat);
  image2.draw_image(210, 240, image_wood);
  image2.draw_image(280, 240, image_wool);
  image2.draw_image(0, 365, image_develop);
}
void Window::Image(std::string url) {}

void Window::printTown(std::string url, int x, int y) {
  int top_height = 5; // primera,segunda,tercera
  int bot_height = 5; // ultima y penultima columna de hexagonos
  int cycle_cord_x = 0;

  DataStructures dataStructures;
  dataStructures.loadLands();
  Node<Land> *temp = dataStructures.lands.head;

  // Cambiar -> mapa de Rutas
  std::string tempUrl = "Images/puebloX.png";

  bot_height += 295;
  for (cycle_cord_x = 500; cycle_cord_x <= 650; cycle_cord_x += 75) {

    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, top_height);
    temp = temp->getNext();
    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, bot_height);
    temp = temp->getNext();
  }

  top_height += 75;
  bot_height = 235;
  for (cycle_cord_x = 465; cycle_cord_x <= 690; cycle_cord_x += 75) {

    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, top_height);
    temp = temp->getNext();
    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, bot_height);
    temp = temp->getNext();
  }

  top_height += 75;
  for (cycle_cord_x = 430; cycle_cord_x <= 655; cycle_cord_x += 75) {
    Window::getInstance().printHexagon(tempUrl, cycle_cord_x, top_height);
    temp = temp->getNext();
  }
}