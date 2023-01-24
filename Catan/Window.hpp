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
  list<Vertex *> vertexesList;

  list<Vertex *>::iterator vertexIterator;

private:
  bool lastIteration = false;
  int lastIterationNumber = 680;
  int vertexIterationNumber;
  string tempImagePath;

public:
  // Land
  void setAndTraverse(sf::RenderWindow &, int, int);
  void iterateLand();
  void lastIterationBehaviour(int);
  bool isLastIteration(int) const;
  bool isLandsListTraversal() const;
  // Vertex
  void iterateVertex();
  bool isTwoLastVertex() const;
  bool isVertexesListTraversal() const;
  void setTempImagePath(string);
  void setPosXYtoLand(double, double);

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

public:
  Window(const Window &) = delete;

  static Window &getInstance() {
    static Window instance;
    return instance;
  }

  void showLandsImagePath();
  void initializeLandsList();
  void initializeVertexesList();
  void showCoordinates(sf::RenderWindow &);
  void goTitleView();
  void goAboutView();
  void goPlayView();
  bool goBack(sf::RenderWindow &);

  void printImages(sf::RenderWindow &, std::string, int, int);
  void printMaterialCard(sf::RenderWindow &);

  void printBoard(sf::RenderWindow &);
  void traverseFirstAndLastRow(int, int, int, sf::RenderWindow &);
  void traverseSecondAndNextToLastRow(int, int, int, sf::RenderWindow &);
  void traverseMiddleRow(int, int, int, sf::RenderWindow &);
  void C_Traversal(sf::RenderWindow &, int, int);

  void loadHexagonNodes(sf::RenderWindow &, list<Vertex *>::iterator,
                        double, double, int);
  void setHexagonCoordinates(list<Vertex *>::iterator, double, double,
                             int);
  double getFormula(int);

  /// ediciones
  void printTowns(sf::RenderWindow &, double , double );

  void updateDisplay();
  void loadStartButtons(sf::RenderWindow &);
  void loadGameButtons(sf::RenderWindow &);

  void setTurn(int);
  void drawTurn(int, int);

private:
  Window() {}
};