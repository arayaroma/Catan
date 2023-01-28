#pragma once
#include "Button.hpp"
#include "Game.hpp"
#include "Graph.hpp"
#include "Label.hpp"
#include "Land.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iterator>
#include "TextBox.h"

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
  list<Land *>::iterator it2;

  list<Vertex *> *vertexesList;

  list<Vertex *>::iterator vertexIterator;

private:
  bool lastIteration = false;
  int lastIterationNumber = 680;
  int vertexIterationNumber;
  string tempImagePath;
  bool firstCalltoPrintBoard = true;
public:
  sf::RenderWindow titleWindow;
  sf::RenderWindow playWindow;
  sf::RenderWindow aboutWindow;
  sf::RenderWindow &actualWindow = titleWindow;
  sf::RenderWindow registerView;

public:
  // Land
  void setAndTraverse(int, int, list<Land *>::iterator);
  void printImages(string, int, int); // Renombrar -> playWindow
  void C_Traversal(int, int, list<Land *>::iterator);
  void loadHexagonNodes(list<Vertex *>::iterator, double, double, int);
  void printTowns(double, double);
  void traverseFirstAndLastRow(int, int, int);
  void traverseSecondAndNextToLastRow(int, int, int);
  void traverseMiddleRow(int, int, int);
  void printBoard();

  /////////////////////////////////////////////////////////////
  void iterateLand();
  void iterateLand2();
  void lastIterationBehaviour(int);
  bool isLastIteration(int) const;
  bool isLandsListTraversal() const;
  void setPosXYtoLand(double, double, list<Land *>::iterator auxIt);
  void initializeLandsList();
  // Vertex
  void iterateVertex();
  bool isTwoLastVertex() const;
  bool isVertexesListTraversal() const;
  void setTempImagePath(string);
  void setPosXYtoVertex(list<Vertex *>::iterator, double, double);
  void initializeVertexesList(list<Land *>::iterator);
  // Graph
  void setPosXYtoVertexesGraph(int, double, double);

  void consolePrintLandAndVertex();

private:
 
    sf::Font font; 

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

  void showCoordinates(sf::RenderWindow &, sf::Event event);
  void showCoordinates(sf::RenderWindow &);
  void goTitleView();
  void goAboutView();
  void goPlayView();

  void loadTextFields(sf::RenderWindow& registerwindow, TextBox &tex1, TextBox& tex2, TextBox& tex3, TextBox& tex4);
  void loadRegisterButtons(sf::RenderWindow& registerwindow, Button& btn1, Button& btn2, Button& btn3);

  void goRegisterView();
  bool goBack(sf::RenderWindow &);

  void printMaterialCard(sf::RenderWindow &);

  double getFormula(int);

  /// ediciones

  void updateDisplay();
  void loadStartButtons(sf::RenderWindow &);
  void loadGameButtons(sf::RenderWindow &);

  void setTurn(int);
  void drawTurn(int, int);

  void registerButton(sf::RenderWindow &window); 


private:

  Window() {}

  bool Player3 = false;
  bool Player4 = false;

};