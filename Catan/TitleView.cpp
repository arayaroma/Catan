#include "TitleView.hpp"

void TitleView::loadView() {
  view.create(sf::VideoMode(1280, 720), "Main Menu");
  image.loadFromFile("Images/inicio.jpg");
  sprite.setTexture(image);
  font.loadFromFile("mononoki.ttf");
  loadLabels();
}

void TitleView::drawView() {
  view.draw(sprite);
  view.draw(title->getTextInstance());
  view.draw(play->getTextInstance());
  view.draw(about->getTextInstance());
  displayView();
}

void TitleView::goView() {
  loadView();
  drawView();

  while (view.isOpen()) {
    while (view.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::MouseButtonPressed:
        if (isMouseLeft(event)) {

          if (isPlayView(event))
            goMenuView();

          if (isAboutView(event))
            goAboutView();
        }
        break;

      case sf::Event::Closed:
        closeView();
        break;
      }
    }
  }
}

void TitleView::goMenuView() {
  closeView();
  MenuView menuView;
  menuView.goView();
}

void TitleView::goAboutView() {
  closeView();
  AboutView aboutView;
  aboutView.goView();
}

void TitleView::loadLabels() {
  title = new Label("Catan", sf::Color::Black, font, sf::Text::Bold, 100, 500.f,
                    50.f);
  play = new Label("Jugar", sf::Color::Black, font, sf::Text::Bold, 100, 500.f,
                   250.f);
  about = new Label("Acerca", sf::Color::Black, font, sf::Text::Bold, 100,
                    500.f, 450.f);
}

bool TitleView::isMouseLeft(sf::Event event) const {
  return (event.mouseButton.button == sf::Mouse::Left);
}

bool TitleView::isAboutView(sf::Event event) const {
  return (event.mouseButton.x > aboutView_X0 &&
          event.mouseButton.y > aboutView_Y0 &&
          event.mouseButton.x < aboutView_X1 &&
          event.mouseButton.y < aboutView_Y1);
}

bool TitleView::isPlayView(sf::Event event) const {
  return (
      event.mouseButton.x > playView_X0 && event.mouseButton.y > playView_Y0 &&
      event.mouseButton.x < playView_X1 && event.mouseButton.y < playView_Y1);
}
