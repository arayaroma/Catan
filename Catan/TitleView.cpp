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
  view.display();
}

void TitleView::goView() {
  Alert *alert = new Alert(NONE, "Titulo",
                           "Esto es un mensaje, con bastante texto indefinido, "
                           "para probar esta alerta");
  loadView();
  drawView();
  alert->goView();

  while (view.isOpen()) {
    while (view.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::MouseButtonPressed:
        if (isMouseLeft(event)) {
          if (isPlayView(event)) {
            view.close();
            RegisterView registerView;
            registerView.goView();
          }

          if (isAboutView(event)) {
            view.close();
            AboutView aboutView;
            aboutView.goView();
          }
        }
        break;

      case sf::Event::Closed:
        view.close();
        break;

      default:
        // if (goBack(titleWindow))
        // titleWindow.close();
        break;
      }
    }
  }
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
