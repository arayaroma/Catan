#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

using std::string;
class TextBox {

public:
  TextBox();
  TextBox(int size, sf::Color color, bool sel, sf::Vector2f position,
          sf::Vector2f sizeBorder, sf::Color colorBorder);
  void setFont(sf::Font &font);
  void setPosition(sf::Vector2f pos);
  void setLimit(bool tOf);
  void setLimit(bool tOf, int lim);
  void setSelected(bool);
  string getText();
  void drawTextbox(sf::RenderWindow &window);
  void typeOn(sf::Event input);
  bool isMouseOver(sf::RenderWindow &window);
  bool isTyping(int) const;
  void setVisible(bool);
  bool isVisible() const;

private:
  sf::RectangleShape border;
  sf::Text textBox;
  std::ostringstream text;
  bool isSelected = false;
  bool _isVisible;
  bool hasLimit = false;
  int limit;

private:
  void inputLogic(int charType);
  void deleteLastCharacter();
};
