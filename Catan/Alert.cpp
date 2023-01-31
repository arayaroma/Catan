#include "Alert.hpp"

Alert::Alert() {
  panel.setPosition(alertPosX + alertOffsetX, alertPosY + alertOffsetY);
  title = new Label();
  message = new Label();
  alertType = NONE;
}

Alert::Alert(sf::RenderWindow &view, string alertType, string titleText,
             string messageText) {
  font.loadFromFile("mononoki.ttf");
  panel.setPosition(50, 50);
  panel.setSize({400, 400});
  panel.setFillColor(sf::Color(0, 235, 45, 255));
  title = new Label(titleText, sf::Color(0, 0, 0, 255), font, sf::Text::Regular,
                    24, alertPosX - 20, alertPosY - 10);
  message = new Label(messageText, sf::Color(0, 0, 0, 255), font,
                      sf::Text::Regular, 22, alertPosX - 10, alertPosY - 5);
  alertType = alertType;
  view.draw(panel);
  view.draw(title->getTextInstance());
  view.draw(message->getTextInstance());
}