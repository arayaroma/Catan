#pragma once
#include "Game.hpp"
#include <SFML/Graphics.hpp>

#define log(x) std::cout << x << std::endl;

class View {

public:
  virtual void goView() = 0;

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

protected:
  Game game;

protected:
  sf::RenderWindow view;
  sf::Texture image;
  sf::Sprite sprite;
  sf::Font font;
  sf::Event event;
};