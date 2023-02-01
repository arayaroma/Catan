#include "Alert.hpp"

Alert::Alert() {
  title = new Label();
  message = new Label();
  alertType = NONE;
}

Alert::Alert(int alertType, string titleText, string messageText) {
  loadView();
  title = new Label(titleText, sf::Color::Black, font, sf::Text::Regular, 24,
                    165, 0);
  message = new Label(separateText(messageText), sf::Color::Black, font,
                      sf::Text::Regular, 22, 20, 50);
  alertType = alertType;
  titleMessage = titleText;
}

// Terminar de arreglar este metodo
string Alert::separateText(string text) {
  int i, cont = 0;
  string modifiedText = "";
  for (i = 0; i < text.length() - 1; i++) {
    if (cont == 26) {
      text += '\n';
      cont = 0;
    }
    modifiedText += text;
    cont++;
  }
  return modifiedText;
}

Alert Alert::noneAlert() { return Alert(); }
Alert Alert::errorAlert() { return Alert(); }
Alert Alert::warningAlert() { return Alert(); }
Alert Alert::confirmationAlert() { return Alert(); }
Alert Alert::informationAlert() { return Alert(); }

Alert Alert::createAlert(int alertType) {
  switch (alertType) {
  case NONE:
    return noneAlert();
    break;
  case ERROR:
    return errorAlert();
    break;
  case WARNING:
    return warningAlert();
    break;
  case CONFIRMATION:
    return confirmationAlert();
    break;
  case INFORMATION:
    return informationAlert();
    break;
  default:
    throw std::invalid_argument("Invalid Alert");
  }
}

void Alert::loadView() {
  view.create(sf::VideoMode(400, 200), titleMessage);
  image.loadFromFile("Images/inicio.jpg");
  sprite.setTexture(image);
  font.loadFromFile("mononoki.ttf");
  view.setFramerateLimit(120);
}

void Alert::drawView() {
  view.draw(sprite);
  view.draw(title->getTextInstance());
  view.draw(message->getTextInstance());
  makeButton();
  drawButton(*okButton);
}

void Alert::goView() {
  loadView();
  while (view.isOpen()) {
    while (view.pollEvent(event)) {
      switch (event.type) {

      case sf::Event::MouseButtonPressed:
        if (isMouseLeftClicked(event))
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

void Alert::makeButton() {
  okButton = new Button("Ok", {60, 30}, 14, sf::Color(0, 25, 225, 255),
                        sf::Color::Black);
  okButton->setPosition({300, 150});
  okButton->setFont(font);
}

void Alert::drawButton(Button &button) {
  if (button.isMouseOver(view))
    button.setBackColor(sf::Color(155, 155, 155, 255));
  else
    button.setBackColor(sf::Color(205, 205, 205, 255));
  button.drawTo(view);
}

sf::Text Alert::getTitle() const { return this->title->getTextInstance(); }