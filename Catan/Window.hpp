#pragma once
#include "Button.hpp"
#include "Game.hpp"
#include "Label.hpp"
#include "Land.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iterator>
#include "TextBox.h"

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

  void showCoordinates(sf::RenderWindow &, sf::Event event);
  void goTitleView();
  void goAboutView();
  void goPlayView();

  void loadTextFields(sf::RenderWindow& registerwindow, TextBox &tex1, TextBox& tex2, TextBox& tex3, TextBox& tex4);
  void loadRegisterButtons(sf::RenderWindow& registerwindow, Button& btn1, Button& btn2, Button& btn3);

  void goRegisterView();
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

  void registerButton(sf::RenderWindow &window); 


private:

  Window() {}

  bool Player3 = false;
  bool Player4 = false;

};