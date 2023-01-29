#include "AboutView.hpp"

void AboutView::loadAboutView() {
  aboutView.create(sf::VideoMode(1280, 720), "About");
  aboutImage.loadFromFile("Images/acercaDe.jpg");
  aboutSprite.setTexture(aboutImage);
  font.loadFromFile("mononoki.ttf");
  loadLabels();
}

void AboutView::loadLabels() {
  back =
      new Label("<---", sf::Color::Black, font, sf::Text::Bold, 18, 20.f, 20.f);
}

void AboutView::drawAboutView() {
  aboutView.draw(aboutSprite);
  aboutView.draw(back->getTextInstance());
  aboutView.display();
}
bool AboutView::isMouseLeft(sf::Event event) const {
  return (event.mouseButton.button == sf::Mouse::Left);
}

bool AboutView::isEscapePressed() const {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return true;
  return false;
}

void AboutView::goAboutView() {
  loadAboutView();
  drawAboutView();

  while (aboutView.isOpen()) {
    while (aboutView.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::KeyPressed:
        if (isEscapePressed()) {
          aboutView.close();
          TitleView titleView;
          titleView.goTitleView();
        }

        break;
      case sf::Event::Closed:
        aboutView.close();
        break;
      }
    }
  }
}