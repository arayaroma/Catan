#pragma once
#include "Button.hpp"
#include "BuyView.hpp"
#include "Dice.hpp"
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
  list<Vertex *> *vertexesList;
  list<Vertex *>::iterator vertexIterator;

  list<Land *> *landsList;
  list<Land *>::iterator it;
  list<Land *>::iterator it2;

  list<Road *>::iterator roadIterator;
  list<City *>::iterator cityIterator;
  list<Town *>::iterator townIterator;

  list<Player *>::iterator playerIterator;

  list<Wheat *>::iterator wheatIterator;
  list<Mineral *>::iterator mineralIterator;
  list<Wool *>::iterator woolIterator;
  list<Wood *>::iterator woodIterator;
  list<Clay *>::iterator clayIterator;

private:
  bool start;
  bool lastIteration = false;
  bool firstCalltoPrintBoard = true;
  int lastIterationNumber = 680;
  int vertexIterationNumber;
  int turnNumber = 0;
  string tempImagePath;
  string url = "";
  int numTurn = 1;
  int numDice;
  Dice diceInstance;
  bool isDiceSpinned = false;
  bool isFirstTurn = true;
  const string dessertType = "Dessert";

  bool isTownBuyClicked = false;
  bool isCityBuyClicked = false;

  bool selectTown = false;

public:
  void goView() override;

private:
  void loadView() override;
  void drawView() override;

public:
  PlayView();
  PlayView(list<Player *> *);

private:
  void loadPlayersRectangle();
  void loadCardsRectangle();
  void loadGameButtons();
  void printMaterialCard();
  void printImages(string, double, double);

  void createLabels();
  void loadthreeXone();

  void createButtons();
  void setButtonOrigins();
  void drawButtons();

  void loadRegisterButtons(Button &btn);
  void loadOcean();

  void drawLabels();
  void printBoard();

  void initializeLandsList();
  void setTurn(int);
  void drawTurn(int, int);
  void setTempImagePath(string);
  bool isLandsListTraversal() const;
  void iterateLand();
  void iterateLand2();
  bool isLastIteration(double) const;
  void lastIterationBehaviour(double);
  void setPosXYtoLand(double, double, list<Land *>::iterator);
  void setAndTraverse(double, double, list<Land *>::iterator);
  void initializeVertexesList(list<Land *>::iterator);
  bool isVertexesListTraversal() const;
  void iterateVertex();
  bool isTwoLastVertex() const;
  void traverseFirstAndLastRow(double, double, double);
  void traverseSecondAndNextToLastRow(double, double, double);
  void traverseMiddleRow(double, double, double);
  void C_Traversal(double, double, list<Land *>::iterator);
  double getFormula(int) const;
  void printTowns(double, double);

  // cambiar nombres
  void printTownsTest();
  void traverseFirstAndLastRowTest(double, double, double);
  void traverseSecondAndNextToLastRowTest(double, double, double);
  void traverseMiddleRowTest(double, double, double);
  void setAndTraverseTest(double, double, list<Land *>::iterator);

  void setPosXYtoVertex(list<Vertex *>::iterator, double, double);
  void loadHexagonNodes(list<Vertex *>::iterator, double, double, int);
  void setPosXYtoVertexesGraph(int, double, double);
  void consolePrintLandAndVertex();

  void showCoordinates(sf::Event event);

  void createLabelNamePlayers();
  void drawLabelNamePlayers();
  void printPlayerCard();
  void createLabelCardPlayer();
  void drawLabelCardPlayer();
  void createLabelFigurePlayer();
  void drawLabelFigurePlayer();
  void printPlayerFigure();
  void drawRectangleShapes();

  void traverseLands(double, double);
  void searhTown(double, double, list<Land *>::iterator);
  bool isTownClicked(list<Vertex *>::iterator, double, double);
  void isPrintedFalse();

  void isTurnButtonClicked(int, int);

  bool getIsVertexGraphClicked(list<Vertex *>::iterator);
  bool getIsVertexGraphPrinted(list<Vertex *>::iterator);

  void setOwnerToVertexGraph(Vertex *);

  void deleteTowntoPlayer();
  void firstTurn();
  void receiveFirstCard(list<Land *>::iterator);
  void receiveFirstMaterialCard();

  void printTownPlayer(list<Vertex *>::iterator, int, int);
  void initializeIteratorTownList();
  void setIsClickedToVertexGraph(list<Vertex *>::iterator);

  void createLabelNumTurn();
  void drawLabelNumTurn();

  void isDiceButtonClicked(int, int);

  void receiveCard(list<Land *>::iterator);
  void receiveMaterialCard(int);

  void createThreePlayersLabel();
  void createFourPlayersLabel();
  bool isThreePlayers() const;
  bool isFourPlayers() const;

  list<Player *>::iterator beginPlayerIterator() const;
  bool isPlayerListTraversal() const;

  bool existsAnOwnerInVertex(list<Vertex *>::iterator);
  bool isVertexesListTraversalInTurn(list<Vertex *>::iterator,
                                     list<Land *>::iterator);
  bool isActualPlayerName(list<Vertex *>::iterator, list<Player *>::iterator);
  void giveCardsToPlayer(list<Land *>::iterator);
  void giveCardsToPlayerFirstTurn(list<Land *>::iterator);

  bool isPlayerTownListEmpty() const;
  bool playerIsPuttingTowns() const;
  bool playerHasPutTwoTowns() const;
  bool isPlayerTownsListTraversal() const;

  void createBuyButton();
  void createTradeButton();
  void createTurnButton();
  void createPButton();
  void createOptionOneButton();
  void createSaveButton();
  void createCloseButton();
  void createDiceButton();

  void printLandsDiceNumbers();
  void createLabelDiceNumber(list<Land *>::iterator);
  bool isDessertLand(list<Land *>::iterator) const;
  void createTempNumberEmpty(list<Land *>::iterator);
  void createTempNumber(list<Land *>::iterator);

private:
  sf::RectangleShape turnRectangleOne, turnRectangleTwo, turnRectangleThree,
      turnRectangleFour;
  void createBuyRectangle();
  void printPlayerBuyFigure();
  void printDevelopCard();
  void clickInTownBuy(int x, int y);
  void clickInCityBuy(int x, int y);
  void isBuyButtonClicked(sf::Event);
  void buildTown();
  void buildCity();
  void payRawMaterialsToBuyTown();
  void payRawMaterialsToBuyCity();
  void deleteClaytoPlayer();
  void deleteWoodtoPlayer();
  void deleteWooltoPlayer();
  void deleteMineraltoPlayer();
  void deleteWheattoPlayer();

  void buyTown(list<Vertex *>::iterator vIterator, double x, double y);
  void printBuyDevelopCard();

private:
  sf::Event eventTest;
  sf::RectangleShape playerRectangle, cardsRectangle, tradeRectangle;
  Label *materialCard, *pricingTable, *turns, *cards, *developCard;
  Label *player1, *player2, *player3, *player4;
  Label *clayCard, *mineralPlayerCard, *wheatPlayerCard, *woodPlayerCard,
      *woolPlayerCard, *firsThreeXone, *secondThreeXone, *thirdThreeXone,
      *fourThreeXone, *tempNumber;
  Label *townPlayer, *cityPlayer, *roadPlayer;
  Label *titleTurn, *labelNumTurn, *infoFisrtTurn, *labelNumDice;
  Button turn, buy, trade, dice, p, option1, save, close;
};