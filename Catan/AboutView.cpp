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
    loadDevelopersPhotos();
    drawView();
  }
}

void AboutView::loadDevelopersPhotos() {
  danielImage.loadFromFile("Images/developersPhotos/danielPhoto.png");
  danielSprite.setTexture(danielImage);
  danielSprite.setPosition(50, 400);
  // danielSprite.setScale(0.5f, 0.5f);

  dilanImage.loadFromFile("Images/developersPhotos/dilanPhoto.png");
  dilanSprite.setTexture(dilanImage);
  dilanSprite.setPosition(50, 500);
  // dilanSprite.setScale(0.5f, 0.5f);

  jesusImage.loadFromFile("Images/developersPhotos/jesusPhoto.png");
  jesusSprite.setTexture(jesusImage);
  jesusSprite.setPosition(50, 600);
  // jesusSprite.setScale(0.5f, 0.5f);

  view.draw(danielSprite);
  view.draw(dilanSprite);
  view.draw(jesusSprite);
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