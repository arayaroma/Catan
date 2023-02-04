#pragma once
#include "Card.hpp"
#include "Figures.hpp"
#include "Land.hpp"
#include "Materials.hpp"
#include "Player.hpp"
#include "DevelopCards.h"
#include "StructureGraph.hpp"
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using std::list;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

/*
  Points:
  If a player has 10 points wins.

  If a player has more than 5 roads consecutive it gets:
  Biggest Path Card - II Points.
  However if someone have more than the highest roads player number
  then immediately it gets the card.

  Knight Cards
  If a player has at least 3 Knight cards, it gets:
  Biggest Army Card - II Points.

  Thief
  If a player gets 7 from the dice, nobody get materials.

  All player that has more than 7 cards of materials, must
  give those cards in the stacks. With even it rounds to down
  like (if a player has 9 cards, it must give 4 cards).

  Move the thief -> Method
  The player can move the Thief wherever it wants
  Then the player stoles a card of material to a player
  that has a Town or a City in that Tile, if there is more
  than one player, the thief chooses which.

  If the dice rolls the number where the thief stands, the players
  that has towns or cities in those numbers get no material, and the
  thief stands in the same place.
*/

class Game {
private:
  string matchName;
  int matchId;
  bool isNumbersLandsSet = false;

public:
  Graph graph;
  int vertexId, vertexJump;
  int graphNodes = 54;

  void setGraph(Graph);
  Graph getGraph() const;

public:
  unordered_map<string, string> imagePaths;

  void setImagePaths(unordered_map<string, string>);
  unordered_map<string, string> getImagePaths() const;

public:
  list<Player *> *players;
  list<Player *>::iterator playerIterator;

  void setPlayersList(list<Player *> *);
  list<Player *> *getPlayersList() const;

public:
  list<Town *> *townsList;
  list<Town *>::iterator townIterator;

  void setTownsList(list<Town *> *);
  list<Town *> *getTownsList() const;

public:
  list<City *> *citiesList;
  list<City *>::iterator cityIterator;

  void setCitiesList(list<City *> *);
  list<City *> *getCitiesList() const;

public:
  list<Road *> *roadsList;
  list<Road *>::iterator roadIterator;

  void setRoadsList(list<Road *> *);
  list<Road *> *getRoadsList() const;

public:
  list<Land *> *landsList;
  list<Land *>::iterator landIterator;

  void setLandsList(list<Land *> *);
  list<Land *> *getLandsList() const;

public:
  list<Vertex *> *vertexesList;

  void setVertexesList(list<Vertex *> *);
  list<Vertex *> *getVertexesList() const;

public:
  Card *specialCard;

  void setSpecialCards(Card *);
  Card *getSpecialCards() const;

public:
  Land land;

  void setLand(Land);
  Land getLand() const;

public:
  stack<Knight *> *knightCards = new stack<Knight *>();

  void setKnightCards(stack<Knight *> *);
  stack<Knight *> *getKnightCards() const;

public:
  stack<Progress *> *progressCards = new stack<Progress *>();

  void setProgressCards(stack<Progress *> *);
  stack<Progress *> *getProgressCards() const;

public:
  stack<VictoryPoints *> *victoryPointCards = new stack<VictoryPoints *>();

  void setVictoryPointsCards(stack<VictoryPoints *> *);
  stack<VictoryPoints *> *getVictoryPointsCards() const;

public:
  stack<Clay *> *clayCards = new stack<Clay *>;

  void setClayCards(stack<Clay *> *);
  stack<Clay *> *getClayCards() const;

public:
  stack<Mineral *> *mineralCards = new stack<Mineral *>;

  void setMineralCards(stack<Mineral *> *);
  stack<Mineral *> *getMineralCards() const;

public:
  stack<Wheat *> *wheatCards = new stack<Wheat *>;

  void setWheatCards(stack<Wheat *> *);
  stack<Wheat *> *getWheatCards() const;

public:
  stack<Wood *> *woodCards = new stack<Wood *>;

  void setWoodCards(stack<Wood *> *);
  stack<Wood *> *getWoodCards() const;

public:
  stack<Wool *> *woolCards = new stack<Wool *>;

  void setWoolCards(stack<Wool *> *);
  stack<Wool *> *getWoolCards() const;

public:
  vector<int> landsNumbers;
  void setLandNumbers(vector<int>);
  vector<int> getLandNumbers() const;

public:
  Game();

  void createGraphVertex();
  void makeGraph();
  void printVertex(list<Vertex *> *);

  void loadMaps();
  void loadLands();
  void loadTilesPaths();
  void loadSpecialCards();
  void loadProgressPaths();
  void loadTowns(Player *);
  void loadRoades(Player *);
  void loadCities(Player *);
  void loadFiguresToPlayer(Player *, int);

  void assignTownsToLand();
  void assignTowns(Land *, int, int, int);
  void assignTownsMiddleRow(Land *, int, int, int);
  void assignTownsLastRows(Land *, int, int, int);

  void makePlayer();
  void makeFigures();
  void makeSpecialCard();
  void makeDevelopCard();
  void makeMaterialCard();

  void printVertexXY() { graph.vertexXY(); }
  void printLand(list<Land *> *);

  void loadLandsNumbers();
  void randomizeLandsNumbers();
  vector<int> getLandsNumbersRandomized();
  void printLandsNumbers(vector<int> const &);

  void setNumbersToLands(list<Land *> *);
  void printDiceNumbersInLands();

  void shuffleLandList();
};
