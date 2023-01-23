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

  void printResources(sf::RenderWindow &, std::string, int, int);
  void printMaterialCard(sf::RenderWindow &);
  void printImageTown(std::string, int, int);

  void printBoard(sf::RenderWindow &);
  void calculateHexagonVertexes(list<Land *>::iterator it, int x, int y);

  void loadHexagonNodes(list<Vertex *>::iterator, double, double);
  double getFormula(int);

  /// ediciones
  void printTown(sf::RenderWindow &);
  void printNeighborsTowns(sf::RenderWindow &, Vertex *temp, std::string url,
                           int x, int y);
  void printNeighborsFinalTowns(sf::RenderWindow &, Vertex *temp,
                                std::string url, int x, int y);
  void setPosXYtoVertex(Vertex *temp, int x, int y);
  ///

  void updateDisplay();
  void loadStartButtons(sf::RenderWindow &playWindow);
  void loadGameButtons(sf::RenderWindow &playWindow);

  void setTurn(int numbrePlayers);
  void drawTurn(int turn, int);

private:
  Window() {}
};