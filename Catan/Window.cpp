#include "Window.hpp"
const unsigned char WHITE[] = {255, 255, 255};
const unsigned char BLUEGREEN[] = { 0,170,255 };
const unsigned char ORANGE[] = { 255,140,0 };
const unsigned char BLACK[] = {0, 0, 0};
const int transparent = 0;
const float opacity = 1;



const char *catan_window_title = "Catan - Title Screen"; 
const char *const image_path = "images/catan_1280x720.jpg";
const char* const image_path_table = "Images/extraCards/pricingTable.jpeg";
unsigned int catan_title_display_width = 1280, catan_title_display_height = 720;
CImg<unsigned char> image(image_path);
CImg<unsigned char> pricingTable(image_path_table);
CImg<unsigned char> image2(image_path);
CImgDisplay title_display(catan_title_display_width, catan_title_display_height,
                          catan_window_title, 3, false, false);

Label *catan = new Label("Catan", 490, 50, 128);
Label *playLabel = new Label("Jugar", 515, 250, 128);
Label *about = new Label("Acerca de", 400, 450, 128);
Label* princingTable = new Label("Pricing Table", 0, 1, 20);
Label* materialCard = new Label("Material Card", 0, 215, 20);
Label* developCard = new Label("Develop Card", 0, 320, 20);
void Window::printTitleScreenLabels() {

  CImgDisplay title_display(catan_title_display_width,
                            catan_title_display_height, catan_window_title, 3,
                            false, false);

  
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
void Window::showDisplay() {
  while (!title_display.is_closed()) {
    title_display.display(image);
    title_display.wait();
    if (title_display.button() && clickLabel(title_display.mouse_x(), title_display.mouse_y())) {
      std::cout << "1" << std::endl;
      showGameDisplay();
    }
  }
}
bool Window::clickLabel(double x, double y) {
    if (x > playLabel->get_x_position() && x < playLabel->get_x_position() + 245 &&
        y > playLabel->get_y_position() && y < playLabel->get_y_position() + 245) {
        return true;}
    return false;
}
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
        image2.draw_image(0, 20, pricingTable);
        image2.draw_text(princingTable->get_x_position(), princingTable->get_y_position(),
            princingTable->mod_get_text(), ORANGE, transparent, opacity,
            princingTable->get_font_size());
        image2.draw_text(materialCard->get_x_position(), materialCard->get_y_position(),
            materialCard->mod_get_text(), ORANGE, transparent, opacity,
            materialCard->get_font_size());
        printMaterialCard();
        image2.draw_image(0, 20, pricingTable);
    }  
}
void Window::printMaterialCard() {
    ///////MATERIAL CARD IMAGE/////////
    CImg<unsigned char> image_clay("Images/resourcesCards/clayCard.png");
    CImg<unsigned char> image_mineral("Images/resourcesCards/mineralCard.png");
    CImg<unsigned char> image_wheat("Images/resourcesCards/wheatCard.png");
    CImg<unsigned char> image_wood("Images/resourcesCards/woodCard.png");
    CImg<unsigned char> image_wool("Images/resourcesCards/woolCard.png");
    CImg<unsigned char> image_develop("Images/extraCards/developCardBackwards.png");

    image2.draw_image(0, 240, image_clay);
    image2.draw_image(70, 240, image_mineral);
    image2.draw_image(140, 240, image_wheat);
    image2.draw_image(210, 240, image_wood);
    image2.draw_image(280, 240, image_wool);
    image2.draw_image(0, 365, image_develop);
}
void Window::Image(std::string url) {

}
void Window::printTown(std::string url, int x, int y) {
    const char* const img = url.c_str();
    CImg <unsigned char>imageTown(img);
    image2.draw_image(x, y, imageTown);
}