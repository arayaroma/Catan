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
  view.display();
}

void AboutView::goView() {
  loadView();
  drawView();

  while (view.isOpen()) {
    while (view.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::KeyPressed:
        if (isEscapePressed()) {
          view.close();
          TitleView titleView;
          titleView.goView();
        }

        break;
      case sf::Event::Closed:
        view.close();
        break;
      }
    }
  }
}

void AboutView::loadLabels() {
  back =
      new Label("<---", sf::Color::Black, font, sf::Text::Bold, 18, 20.f, 20.f);
}

bool AboutView::isMouseLeft(sf::Event event) const {
  return (event.mouseButton.button == sf::Mouse::Left);
}

bool AboutView::isEscapePressed() const {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return true;
  return false;
}
