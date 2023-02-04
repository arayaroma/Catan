#pragma once
#include "Game.hpp"
#include <SFML/Graphics.hpp>

#define log(x) std::cout << x << std::endl;

class View {

public:
  virtual void goView() = 0;
  View() { game.players = new list<Player *>(); }

private:
  virtual void loadView() = 0;
  virtual void drawView() = 0;

public:
  virtual bool isMousePressed(sf::Event event) const {
    return (event.type == sf::Event::MouseButtonPressed);
  }

  virtual bool isMouseLeftClicked(sf::Event event) const {
    return (event.mouseButton.button == sf::Mouse::Left);
  }

  virtual bool isMouseRightClicked(sf::Event event) const {
    return (event.mouseButton.button == sf::Mouse::Right);
  }

  virtual int getMousePositionX(sf::RenderWindow &view) const {
    return sf::Mouse::getPosition(view).x;
  }

  virtual int getMousePositionY(sf::RenderWindow &view) const {
    return sf::Mouse::getPosition(view).y;
  }

  virtual bool isReturnPressed() const {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Return));
  }

  virtual bool isEndPressed() const {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::End));
  }

  virtual bool isEscapePressed() const {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
  }

  virtual bool isQKeyPressed() const {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
  }

  virtual void closeView() { view.close(); }
  virtual void displayView() { view.display(); }
  virtual void clearView() { view.clear(); }

protected:
  Game game;

protected:
  sf::RenderWindow view;
  sf::Texture image;
  sf::Texture OceanImg;
  sf::Sprite sprite;
  sf::Sprite OCeanSprite;
  sf::Font font;
  sf::Event event;
};