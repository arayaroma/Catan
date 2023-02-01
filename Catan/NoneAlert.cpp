#include "NoneAlert.hpp"

NoneAlert::NoneAlert() {}

NoneAlert::NoneAlert(string titleMessage, string bodyMessage) {
  titleLabel = new Label(titleMessage, sf::Color::Black, font,
                         sf::Text::Regular, 24, 160, 5);
  messageLabel = new Label(bodyMessage, sf::Color::Black, font,
                           sf::Text::Regular, 16, 20, 70);
  titleMessage = titleMessage;
  bodyMessage = bodyMessage;
  alertType = NONE;
}

void NoneAlert::makeOkButton() {
  okButton =
      Button("Ok", {60, 30}, 14, sf::Color(0, 25, 225, 255), sf::Color::Black);
  okButton.setPosition({160, 150});
  okButton.setFont(font);
}

void NoneAlert::drawButton(Button &button) {
  makeOkButton();
  if (button.isMouseOver(view))
    button.setBackColor(sf::Color(155, 155, 155, 255));
  else
    button.setBackColor(sf::Color(205, 205, 205, 255));
  button.drawTo(view);
}

void NoneAlert::loadImageIcon() {
  imageIcon.loadFromFile(noneAlertPath);
  imageIconSprite.setTexture(imageIcon);
  imageIconSprite.setPosition(2, 2);
}

void NoneAlert::loadView() {
  view.create(sf::VideoMode(400, 200), titleMessage);
  image.loadFromFile("Images/alerts/background.png");
  sprite.setTexture(image);
  font.loadFromFile("mononoki.ttf");
  view.setFramerateLimit(120);
}

void NoneAlert::drawView() {
  loadImageIcon();
  view.draw(sprite);
  view.draw(imageIconSprite);
  view.draw(titleLabel->getTextInstance());
  view.draw(messageLabel->getTextInstance());
  drawButton(okButton);
}

void NoneAlert::goView() {
  loadView();
  drawView();
  while (view.isOpen()) {
    while (view.pollEvent(event)) {
      switch (event.type) {

      case sf::Event::MouseButtonPressed:
        if (isMouseLeftClicked(event) && okButton.isMouseOver(view))
          view.close();

        view.close();
      case sf::Event::Closed:
        view.close();
        break;
      }
    }
    view.clear();
    drawView();
    view.display();
  }
}