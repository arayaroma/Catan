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

// leftVariance: greater = lefter
void Button::setPosition(sf::Vector2f position, int leftVariance) {
  button.setPosition(position);
  xPos = (position.x + button.getGlobalBounds().width / leftVariance) -
         (text.getGlobalBounds().width / leftVariance);
  yPos = (position.y + button.getGlobalBounds().height / leftVariance) -
         (text.getGlobalBounds().height / leftVariance);
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

  buttonWidth = getButtonWidth();
  buttonHeight = getButtonHeight();

  return (isInsideButton());
}

bool Button::isInsideButton() const {
  return (mousePosX < buttonWidth && mousePosX > buttonPosX &&
          mousePosY < buttonHeight && mousePosY > buttonPosY);
}

float Button::getButtonPosX() { return button.getPosition().x; }
float Button::getButtonPosY() { return button.getPosition().y; }

float Button::getButtonWidth() {
  return button.getPosition().x + button.getGlobalBounds().width;
}

float Button::getButtonHeight() {
  return button.getPosition().y + button.getGlobalBounds().height;
}

float Button::getMousePosX(sf::RenderWindow &view) {
  return static_cast<float>(sf::Mouse::getPosition(view).x);
}

float Button::getMousePosY(sf::RenderWindow &view) {
  return static_cast<float>(sf::Mouse::getPosition(view).y);
}

bool Button::isPressed(sf::Event event) {
  return (isInsideButton() && isMouseLeftClickedButton(event));
}

bool Button::isMouseLeftClickedButton(sf::Event event) {
  return _isPressed = (event.mouseButton.button == sf::Mouse::Left);
}