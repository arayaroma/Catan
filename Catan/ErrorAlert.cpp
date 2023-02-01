#include "ErrorAlert.hpp"

ErrorAlert::ErrorAlert() {}

ErrorAlert::ErrorAlert(string titleMessage, string bodyMessage) {
  titleLabel = new Label(titleMessage, sf::Color::Black, font,
                         sf::Text::Regular, 24, 160, 5);
  messageLabel = new Label(separateText(bodyMessage), sf::Color::Black, font,
                           sf::Text::Regular, 16, 20, 50);
  titleMessage = titleMessage;
  bodyMessage = bodyMessage;
  alertType = NONE;
}

void ErrorAlert::makeOkButton() {
  okButton =
      Button("Ok", {60, 30}, 14, sf::Color(0, 25, 225, 255), sf::Color::Black);
  okButton.setPosition({160, 150}, 5);
  okButton.setFont(font);
}

void ErrorAlert::drawButton(Button &button) {
  makeOkButton();
  if (button.isMouseOver(view))
    button.setBackgroundColor(sf::Color(155, 155, 155, 255));
  else
    button.setBackgroundColor(sf::Color(205, 205, 205, 255));
  button.drawTo(view);
}

void ErrorAlert::loadImageIcon() {
  imageIcon.loadFromFile(errorAlertPath);
  imageIconSprite.setTexture(imageIcon);
  imageIconSprite.setPosition(2, 2);
}

void ErrorAlert::loadView() {
  view.create(sf::VideoMode(400, 200), titleMessage);
  image.loadFromFile("Images/alerts/background.png");
  sprite.setTexture(image);
  font.loadFromFile("mononoki.ttf");
  view.setFramerateLimit(120);
}

void ErrorAlert::drawView() {
  loadImageIcon();
  view.draw(sprite);
  view.draw(imageIconSprite);
  view.draw(titleLabel->getTextInstance());
  view.draw(messageLabel->getTextInstance());
  drawButton(okButton);
}

void ErrorAlert::goView() {
  loadView();
  drawView();
  while (view.isOpen()) {
    while (view.pollEvent(event)) {
      switch (event.type) {

      case sf::Event::MouseButtonPressed:
        if (isOkButtonPressed(event))
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