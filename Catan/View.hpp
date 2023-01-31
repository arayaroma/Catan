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

protected:
  Game game;

protected:
  sf::RenderWindow view;
  sf::Texture image;
  sf::Sprite sprite;
  sf::Font font;
  sf::Event event;

  list<Player*>* players;
  list<Player*>::iterator playerIterator;
};