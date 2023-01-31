#pragma once
#include "Label.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>
#include <string>

#define pi 3.14159265358979323846
#define firstAngle (3 * pi) / 2
#define secondAngle (5 * pi) / 4
#define thirdAngle (7 * pi) / 4
#define fourthAngle (3 * pi) / 4
#define fifthAngle pi / 4
#define sexthAngle pi / 2
#define landsRadius 37.5

using std::list;
using std::string;

class PlayView : public View {
public:
  list<Land *> *landsList;
  list<Land *>::iterator it;
  list<Land *>::iterator it2;

  list<Vertex *> *vertexesList;
  list<Vertex *>::iterator vertexIterator;

private:
  bool start;
  bool lastIteration = false;
  bool firstCalltoPrintBoard = true;
  int lastIterationNumber = 680;
  int vertexIterationNumber;
  int turnNumber;
  string tempImagePath;

public:
  void goView() override;

private:
  void loadView() override;
  void drawView() override;

private:
  void loadPlayersRectangle();
  void loadCardsRectangle();
  void loadGameButtons();
  void printMaterialCard();
  void printImages(string, int, int);
  void createLabels();
  void drawLabels();
  void printBoard();
  void initializeLandsList();
  void setTurn(int);
  void drawTurn(int, int);
  void setTempImagePath(string);
  bool isLandsListTraversal() const;
  void iterateLand();
  void iterateLand2();
  bool isLastIteration(int) const;
  void lastIterationBehaviour(int);
  void setPosXYtoLand(double, double, list<Land *>::iterator);
  void setAndTraverse(int, int, list<Land *>::iterator);
  void initializeVertexesList(list<Land *>::iterator);
  bool isVertexesListTraversal() const;
  void iterateVertex();
  bool isTwoLastVertex() const;
  void traverseFirstAndLastRow(int, int, int);
  void traverseSecondAndNextToLastRow(int, int, int);
  void traverseMiddleRow(int, int, int);
  void C_Traversal(int, int, list<Land *>::iterator);
  double getFormula(int) const;
  void printTowns(double, double);
  void setPosXYtoVertex(list<Vertex *>::iterator, double, double);
  void loadHexagonNodes(list<Vertex *>::iterator, double, double, int);
  void setPosXYtoVertexesGraph(int, double, double);
  void consolePrintLandAndVertex();

  void isPrinted(int);
  void showCoordinates(sf::Event event);

private:
  sf::RectangleShape playerRectangle, cardsRectangle;
  Label *materialCard, *pricingTable, *turns, *cards;
};