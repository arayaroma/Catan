#pragma once
#include "Button.hpp"
#include "Game.hpp"
#include "Label.hpp"
#include "Land.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iterator>

#define pi 3.14159265358979323846
#define firstAngle pi / 2
#define secondAngle (3 * pi) / 4
#define thirdAngle pi / 4
#define fourthAngle (5 * pi) / 4
#define fifthAngle (7 * pi) / 4
#define sexthAngle (3 * pi) / 2
#define landsRadius 37.5

using std::list;

class Window {
public:
  Game game;
  list<Land *> *landsList;
  list<Land *>::iterator it;
private:
  sf::Font font;
  Button Prueba;
  Button btnTrade;
  Button btnBuy;
  Button btnTurns;
  Button btnClose;
  Button btnOpcional1;
  Button btnOpcional2;

  sf::RectangleShape prueba;
  sf::RectangleShape trade;
  sf::RectangleShape buy;
  sf::RectangleShape Turnos;
  sf::RectangleShape close2;
  sf::RectangleShape opcional1;
  sf::RectangleShape opcional2;
  sf::RectangleShape turn;

  int i = 100;
  int turnNumber = 0;
  bool lastIteration = false;
public:
  Window(const Window &) = delete;

  static Window &getInstance() {
    static Window instance;
    return instance;
  }

  void showLandsImagePath();
  void initializeLandsList();

  void showCoordinates(sf::RenderWindow &);
  void goTitleView();
  void goAboutView();
  void goPlayView();
  bool goBack(sf::RenderWindow &);

  void printImages(sf::RenderWindow &, std::string, int, int);
  void printMaterialCard(sf::RenderWindow &);

  void printBoard(sf::RenderWindow &);
  void traverseFirstAndLastRow(int x, int top_height, int bot_height, sf::RenderWindow& window);
  void traverseSecondAndNextToLastRow(int x, int top_height, int bot_height, sf::RenderWindow& window);
  void traverseMiddleRow(int x, int top_height, int bot_height, sf::RenderWindow& window);
  void cFormTraverse(sf::RenderWindow& window,list<Land *>::iterator it, int x, int y,bool);

  void loadHexagonNodes(sf::RenderWindow& window,list<Vertex *>::iterator, double, double, int iterationNumber);
  void setHexagonCoordinates(list<Vertex*>::iterator, double, double, int iterationNumber);
  double getFormula(int);


  /// ediciones
  void printTowns(sf::RenderWindow &,double x, double y);
  void setPosXYtoVertex(list<Vertex*>::iterator it, int x, int y);
  ///

  void updateDisplay();
  void loadStartButtons(sf::RenderWindow &playWindow);
  void loadGameButtons(sf::RenderWindow &playWindow);

  void setTurn(int numbrePlayers);
  void drawTurn(int turn, int);

private:
  Window() {}
};