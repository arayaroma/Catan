#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using std::string;

class Button {
private:
  bool _isPressed;

public:
  Button();
  Button(string, sf::Vector2f, int, sf::Color, sf::Color);

public:
  bool isPressed() const;
  void setFont(sf::Font &);
  void setBackgroundColor(sf::Color);
  void setForegroundColor(sf::Color);
  void setPosition(sf::Vector2f);
  void setPositionLeft(sf::Vector2f);
  void setPositionLefter(sf::Vector2f);
  void drawTo(sf::RenderWindow &);
  bool isMouseOver(sf::RenderWindow &);

private:
  sf::RectangleShape button;
  sf::Text text;
  float buttonPosX, buttonPosY, mousePosX, mousePosY, buttonWidth, buttonHeight,
      xPos, yPos;

private:
  float getButtonPosX();
  float getButtonPosY();
  float getMousePosX(sf::RenderWindow &);
  float getMousePosY(sf::RenderWindow &);
  bool isInsideButton() const;
};
