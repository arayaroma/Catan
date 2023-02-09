#include "AboutView.hpp"

void AboutView::loadView() {
  view.create(sf::VideoMode(1280, 720), "About");
  image.loadFromFile("Images/acercaDe.jpg");
  sprite.setTexture(image);
  font.loadFromFile("mononoki.ttf");
  loadLabels();
}

void AboutView::drawView() {
  view.draw(sprite);
  loadDevelopersPhotos();
  displayView();
}

void AboutView::goView() {
  loadView();
  loadDevelopersPhotos();
  drawView();

  while (view.isOpen()) {
    while (view.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::KeyPressed:
        if (isQKeyPressed())
          goTitleView();

        break;
      case sf::Event::Closed:
        closeView();
        break;
      }
    }
    
    drawView();
  }
}
void AboutView::loadDevelopersPhotos() {
    printImages("Images/developersPhotos/jesusPhoto.png", 50, 500);
    printImages("Images/developersPhotos/dilanPhoto.png", 50, 600);
    printImages("Images/developersPhotos/danielPhoto.png", 50, 400);
}
void AboutView::printImages(string imagePath, double posX, double posY) {
    sf::Texture path;
    path.loadFromFile(imagePath);
    sf::Sprite tempSprite(path);
    tempSprite.setPosition(static_cast<float>(posX), static_cast<float>(posY));
    view.draw(tempSprite);
}

void AboutView::goTitleView() {
  closeView();
  TitleView titleView;
  titleView.goView();
}

void AboutView::loadLabels() {
  back =
      new Label("<---", sf::Color::Black, font, sf::Text::Bold, 18, 20.f, 20.f);
}