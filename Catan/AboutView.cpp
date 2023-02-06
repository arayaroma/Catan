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
  view.draw(back->getTextInstance());
  displayView();
}

void AboutView::goView() {
  loadView();
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
  }
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