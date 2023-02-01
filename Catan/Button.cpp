#include "Button.hpp"

Button::Button() {}

Button::Button(string textMessage, sf::Vector2f size, int characterSize,
               sf::Color backgroundColor, sf::Color foregroundColor) {
  text.setString(textMessage);
  text.setFillColor(foregroundColor);
  text.setCharacterSize(characterSize);
  button.setSize(size);
  button.setFillColor(backgroundColor);
}

void Button::setFont(sf::Font &font) { text.setFont(font); }

void Button::setBackgroundColor(sf::Color backgroundColor) {
  button.setFillColor(backgroundColor);
}

void Button::setForegroundColor(sf::Color foregroundColor) {
  text.setFillColor(foregroundColor);
}

void Button::setPosition(sf::Vector2f position) {
  button.setPosition(position);
  xPos = (position.x + button.getGlobalBounds().width / 3) -
         (text.getGlobalBounds().width / 3);
  yPos = (position.y + button.getGlobalBounds().height / 3) -
         (text.getGlobalBounds().height / 3);
  text.setPosition({xPos, yPos});
}

void Button::setPositionLeft(sf::Vector2f position) {
  button.setPosition(position);
  xPos = (position.x + button.getGlobalBounds().width / 5) -
         (text.getGlobalBounds().width / 5);
  yPos = (position.y + button.getGlobalBounds().height / 5) -
         (text.getGlobalBounds().height / 5);
  text.setPosition({xPos, yPos});
}

void Button::setPositionLefter(sf::Vector2f position) {
  button.setPosition(position);
  xPos = (position.x + button.getGlobalBounds().width / 7) -
         (text.getGlobalBounds().width / 7);
  yPos = (position.y + button.getGlobalBounds().height / 5) -
         (text.getGlobalBounds().height / 5);
  text.setPosition({xPos, yPos});
}

void Button::drawTo(sf::RenderWindow &view) {
  view.draw(button);
  view.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow &view) {
  mousePosX = getMousePosX(view);
  mousePosY = getMousePosY(view);

  buttonPosX = getButtonPosX();
  buttonPosY = getButtonPosY();

  buttonWidth = button.getPosition().x + button.getGlobalBounds().width;
  buttonHeight = button.getPosition().y + button.getGlobalBounds().height;

  return (isInsideButton());
}

bool Button::isInsideButton() const {
  return (mousePosX < buttonWidth && mousePosX > buttonPosX &&
          mousePosY < buttonHeight && mousePosY > buttonPosY);
}

float Button::getButtonPosX() { return button.getPosition().x; }
float Button::getButtonPosY() { return button.getPosition().y; }

float Button::getMousePosX(sf::RenderWindow &view) {
  return static_cast<float>(sf::Mouse::getPosition(view).x);
}

float Button::getMousePosY(sf::RenderWindow &view) {
  return static_cast<float>(sf::Mouse::getPosition(view).y);
}

bool Button::isPressed() const { return this->_isPressed; }