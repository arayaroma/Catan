#pragma once
#include "Button.hpp"
#include "Game.hpp"
#include "Graph.hpp"
#include "Label.hpp"
#include "Land.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iterator>

#define log(x) std::cout << x << std::endl;

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
  sf::RenderWindow titleWindow;
  sf::RenderWindow playWindow;
  sf::RenderWindow aboutWindow;
  sf::RenderWindow &actualWindow = titleWindow;

public:
  // Land
  void setAndTraverse(int, int);
  void printImages(string, int, int); // Renombrar -> playWindow
  void C_Traversal(int, int);
  void loadHexagonNodes(list<Vertex *>::iterator, double, double, int);
  void printTowns(double, double);
  void traverseFirstAndLastRow(int, int, int);
  void traverseSecondAndNextToLastRow(int, int, int);
  void traverseMiddleRow(int, int, int);
  void printBoard();

  /////////////////////////////////////////////////////////////
  void iterateLand();
  void lastIterationBehaviour(int);
  bool isLastIteration(int) const;
  bool isLandsListTraversal() const;
  void setPosXYtoLand(double, double);
  void initializeLandsList();
  // Vertex
  void iterateVertex();
  bool isTwoLastVertex() const;
  bool isVertexesListTraversal() const;
  void setTempImagePath(string);
  void setPosXYtoVertex(list<Vertex *>::iterator, double, double);
  void initializeVertexesList();
  // Graph
  void setPosXYtoVertexesGraph(int, double, double);

  void consolePrintLandAndVertex();

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

  // IMPRIMIR
  // CARGAR

  void showLandsImagePath();

  void showCoordinates(sf::RenderWindow &);
  void goTitleView();
  void goAboutView();
  void goPlayView();
  bool goBack(sf::RenderWindow &);

  void printMaterialCard(sf::RenderWindow &);


  void setHexagonCoordinates(list<Vertex *>::iterator, double, double, int);
  double getFormula(int);

  /// ediciones

  void updateDisplay();
  void loadStartButtons(sf::RenderWindow &);
  void loadGameButtons(sf::RenderWindow &);

  void setTurn(int);
  void drawTurn(int, int);

private:
  Window() {}
};