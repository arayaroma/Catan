#pragma once
#include "Alert.hpp"
#include "Button.hpp"
#include "BuyView.hpp"
#include "Dice.hpp"
#include "ErrorAlert.hpp"
#include "FileHandler.hpp"
#include "Label.hpp"
#include "NoneAlert.hpp"
#include "TradeView.h"
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
  BuyView buyView = BuyView();
  TradeView tradeView = TradeView();
  list<Vertex *> *vertexesList;
  list<Vertex *>::iterator vertexIterator;

  list<Land *> *landsList;
  list<Land *>::iterator it;
  list<Land *>::iterator it2;

  list<Road *>::iterator roadIterator;
  list<City *>::iterator cityIterator;
  list<Town *>::iterator townIterator;

  list<Progress *>::iterator progressIterator;
  list<VictoryPoints *>::iterator victoryPointsIterator;
  list<Knight *>::iterator knightIterator;

  list<Player *>::iterator playerIterator;

  list<Player *>::iterator playerIterator2;
  list<Player *>::iterator playerIterator3;
  list<Player *>::iterator playerIterator4;

  list<Wheat *>::iterator wheatIterator;
  list<Mineral *>::iterator mineralIterator;
  list<Wool *>::iterator woolIterator;
  list<Wood *>::iterator woodIterator;
  list<Clay *>::iterator clayIterator;

private:
  Dice diceInstance;
  const string dessertType = "Dessert";
  string ownerBiggestArmy;
  string namePlayertheLargestArmy = "";
  string tempImagePath;
  string url = "";

  int lastIterationNumber = 680;
  int vertexIterationNumber;
  int turnNumber = 0;
  int numTurn = 1;
  int numDice;

  bool start;
  bool isDesert = false;
  bool isFirstTurn = true;
  bool selectTown = false;
  bool selectCity = false;
  bool isMonopolyBuy = false;
  bool isDiceSpinned = false;
  bool lastIteration = false;
  bool isParentClicked = false;
  bool isAdjacentVertex = false;
  bool istheLargestArmy = false;
  bool isTownBuyClicked = false;
  bool isCityBuyClicked = false;
  bool isMaterialPressed = false;
  bool isCLayTradeClicked = false;
  bool isWoodTradeClicked = false;
  bool isWoolTradeClicked = false;
  bool isWheatTradeClicked = false;
  bool firstCalltoPrintBoard = true;
  bool isMineralTradeClicked = false;
  bool isPlayerNormalPortNeighbor = false;
  bool isPlayerSpecialPortNeighbor = false;

public:
  void goView() override;

private:
  void loadView() override;
  void drawView() override;

public:
  PlayView();
  PlayView(Game &);
  PlayView(list<Player *> *, string);

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

  void checkMaterialClicks();
  bool isHexagonsClicked(float, float);
  bool isRightClicked(float, float);
  bool isMaterialClick(float, float);
  bool isProgressClick(float, float);

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
  void drawLabelDevelopCardPLayer();
  void printPlayerFigure();
  void printPlayerDevelopCard();
  void createLabelPlayerDevelopCard();
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
  void deleteCitytoPlayer();
  void addTownToPlayer();
  void firstTurn();
  void receiveFirstCard(list<Land *>::iterator);
  void receiveFirstMaterialCard();

  void printTownPlayer(list<Vertex *>::iterator, int, int);
  void initializeIteratorTownList();
  void initializeIteratorCityList();
  void setIsClickedToVertexGraph(list<Vertex *>::iterator);

  void createLabelNumTurn();
  void createLabelScorePlayer();
  void drawLabelNumTurn();
  void createLabelMaterialCardGame();
  void drawLabelMaterialGame();
  void isDiceButtonClicked(sf::Event event);

  void receiveCard(list<Land *>::iterator);
  void receiveMaterialCard(int);

  void hexagonsMethod();
  void resourcesMethod();
  void progressMethod();
  void eventPlayerMethod();
  void shopMethod();
  void largestArmy();
  void firstTraversalLand();

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
  void giveCardsToPlayerCity(list<Land *>::iterator);
  void giveCardsToPlayerFirstTurn(list<Land *>::iterator);

  bool isPlayerTownListEmpty() const;
  bool playerIsPuttingTowns() const;
  bool playerHasPutTwoTowns() const;
  bool isPlayerTownsListTraversal() const;

  bool isClosePressed();
  void createTradeButton();
  void createInfoTradeButton();
  void createDiscoveryButton();
  void createMonopolyButton();
  void createInfoBuyButton();
  void createTurnButton();
  void createPButton();
  void createDiceButton();

  void isInfoBuyClicked(sf::Event);
  void isInfoTradeClicked(sf::Event);

  void printLandsDiceNumbers();
  void createLabelDiceNumber(list<Land *>::iterator);
  bool isDessertLand(list<Land *>::iterator);
  void createTempNumberEmpty(list<Land *>::iterator);
  void createTempNumber(list<Land *>::iterator);

  void clickClayTrade(int x, int y);
  void clickMineralTrade(int x, int y);
  void clickWoodTrade(int x, int y);
  void clickWoolTrade(int x, int y);
  void clickWheatTrade(int x, int y);

private:
  sf::RectangleShape turnRectangleOne, turnRectangleTwo, turnRectangleThree,
      turnRectangleFour;
  void createBuyRectangle();
  void printPlayerBuyFigure();
  void clickInTownBuy(int x, int y);
  void clickInCityBuy(int x, int y);
  void clickInDevelopCardBuy(int x, int y);
  void clickTradeButton(sf::Event);
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

  bool deleteWoodCards();
  bool deleteWoolCards();
  bool deleteMineralCards();
  bool deleteClayCards();
  bool deleteWheatCards();
  void buyTown(list<Vertex *>::iterator vIterator, double x, double y);
  void buyCity(list<Vertex *>::iterator vIterator, double x, double y);
  void printBuyDevelopCard();

  void buyDevelopCard();
  void receiveBoughtDevelopCard();
  void deleteKnightCard();
  void deleteVictoryCard();
  void deleteProgressCard(int);

  void traverseLandsToTrade();
  bool landIsNormalPortNeighbor(list<Land *>::iterator it);
  bool landIsSpecialPortNeighbor(list<Land *>::iterator it);
  bool townIsNormalPortNeighbor(list<Vertex *>::iterator it);
  bool townIsSpecialPortNeighbor(list<Vertex *>::iterator it);
  void townsInPort(list<Land *>::iterator it);
  void tradePossible();
  void tradeNormal();
  void tradeSpecial();
  void tradeCard();

  void loadBiggestArmyCard();
  void saveMatchActualState();
  bool theLargestArmy();
  void compareBiggestArmyPlayer();

  void playMonopolyCard(sf::Event);
  void playDiscoveryCard(sf::Event);

  void getClaysPlayersToMonopoly();
  void getWoodsPlayersToMonopoly();
  void getWoolsPlayersToMonopoly();
  void getMineralsPlayersToMonopoly();
  void getWheatsPlayersToMonopoly();

  bool adjacentVertex(list<Vertex *>::iterator vIterator);
  void parentAdjacentVertex(list<Vertex *>::iterator vIterator,
                            list<Vertex *>::iterator vIteratorAux);
  void traverseLandsToAdjacentVertex(list<Vertex *>::iterator vIterator);
  void printFiguresGame();
  void deleteTowns();
  void deleteCities();

private:
  sf::Event eventTest;
  sf::RectangleShape playerRectangle, cardsRectangle, buyRectangle;
  Label materialCard, pricingTable, turns, cards, developCard, labelBuy;
  Label player1, player2, player3, player4, owner, ownerName;
  Label clayCard, mineralPlayerCard, wheatPlayerCard, woodPlayerCard,
      woolPlayerCard, firsThreeXone, secondThreeXone, thirdThreeXone,
      fourThreeXone, tempNumber;
  Label townPlayer, cityPlayer, roadPlayer;
  Label titleTurn, labelNumTurn, infoFisrtTurn, labelNumDice, scorePlayer,
      titleScorePlayer;
  Label knight, progress, victory, town, city, road;
  Label woodGame, woolGame, clayGame, mineralGame, wheatGame, numDevelopCard;
  Button turn, buy, trade, dice, p, option1, save, close, howTrade, howBuy,
      progreessConstruccion, progreessMonopoly, progreessDiscovery;
};