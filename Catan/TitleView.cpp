#include "TitleView.hpp"

void TitleView::loadTitleView() {
  titleWindow.create(sf::VideoMode(1280, 720), "Main Menu");
  titleImage.loadFromFile("Images/inicio.jpg");
  titleSprite.setTexture(titleImage);
  font.loadFromFile("mononoki.ttf");
  loadLabels();
}

void TitleView::loadLabels() {
  title = new Label("Catan", sf::Color::Black, font, sf::Text::Bold, 100, 500.f,
                    50.f);
  play = new Label("Jugar", sf::Color::Black, font, sf::Text::Bold, 100, 500.f,
                   250.f);
  about = new Label("Acerca", sf::Color::Black, font, sf::Text::Bold, 100,
                    500.f, 450.f);
}

void TitleView::drawTitleView() {
  titleWindow.draw(titleSprite);
  titleWindow.draw(title->getTextInstance());
  titleWindow.draw(play->getTextInstance());
  titleWindow.draw(about->getTextInstance());
  titleWindow.display();
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

void TitleView::goTitleView() {
  loadTitleView();
  drawTitleView();

  while (titleWindow.isOpen()) {
    while (titleWindow.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        titleWindow.close();
        break;
      case sf::Event::MouseButtonPressed:
        if (isMouseLeft(event)) {
          if (isPlayView(event)) {
            titleWindow.close();
            RegisterView registerView;
            registerView.goRegisterView();
          }

          if (isAboutView(event)) {
            titleWindow.close();
            AboutView aboutView;
            aboutView.goAboutView();
          }
        }
        break;

      default:
        // if (goBack(titleWindow))
        // titleWindow.close();
        break;
      }
    }
  }
}