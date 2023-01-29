#pragma once
#include "Game.hpp"
#include "Label.hpp"
#include "Window.hpp"
#include <SFML/Graphics.hpp>
#include <string>

using std::string;

class PlayView {
public:
  Window window;
  void goPlayView();

private:
  void loadPlayView();
  void drawPlayView();
  void loadGameButtons();
  void printMaterialCard();
  void printImages(string, int, int);
  void createLabels();
  void drawLabels();
  void printBoard();
  void initializeLandsList();
  void setTurn(int);
  void drawTurn(int, int);

private:
  bool start;
  sf::RenderWindow playView;
  sf::Texture playImage;
  sf::Sprite playSprite;
  sf::Font font;
  sf::Event event;
  sf::RectangleShape playerRectangle, cardsRectangle;
  Label *materialCard, *pricingTable, *turns, *cards;
  bool lastIteration;
  int lastIterationNumber;
  int turnNumber;
};
