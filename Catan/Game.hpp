#pragma once
#include "Card.hpp"
#include "Figures.hpp"
#include "Land.hpp"
#include "Materials.hpp"
#include "Player.hpp"
#include "ProgressCards.hpp"
#include "StructureGraph.hpp"
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <unordered_map>

using std::list;
using std::stack;
using std::string;
using std::unordered_map;

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
public:
  Graph graph;
  int vertexId, vertexJump;
  const int graphNodes = 54;

public:
  void createGraphVertex();

public:
  unordered_map<string, string> imagePaths;
  Land land;

  list<Town *> *townsList;
  list<Player *> *players;
  list<Player*>::iterator playerIterator;
  list<City *> *citiesList;
  list<City*>::iterator cityIterator;

  list<Road *> *roadsList;
  list<Road*>::iterator roadIterator;

  list<Land *> *landsList;
  list<Land *>::iterator landIterator;
  Card *specialCard;

  list<Vertex *> *vertexesList;

  stack<Knight *> *knightCards = new stack<Knight *>();
  stack<Progress *> *progressCards = new stack<Progress *>();
  stack<VictoryPoints *> *victoryPointCards = new stack<VictoryPoints *>();

  stack<Clay *> *clayCards = new stack<Clay *>;
  stack<Mineral *> *mineralCards = new stack<Mineral *>;
  stack<Wheat *> *wheatCards = new stack<Wheat *>;
  stack<Wood *> *woodCards = new stack<Wood *>;
  stack<Wool *> *woolCards = new stack<Wool *>;

public:
  list<Land *> *getLandsList() const { return this->landsList; }

public:
  Game();

  void loadMaps();
  void loadSpecialCards();
  void loadProgressPaths();
  void loadTilesPaths();

  void play();
  void build();

  void tradeMaterials();
  void loadLands();

  void assignTownsToLand();
  void assignTowns(Land *, int, int, int);
  void assignTownsMiddleRow(Land *, int, int, int);
  void assignTownsLastRows(Land *, int, int, int);
  void makeMaterialCard();
  void makeDevelopCard();
  void playDevelopCard();
  void makeFigures();
  void makeConstructionCostsCard();
  void makeSpecialCard();
  void printVertexXY() { graph.vertexXY(); }
  void makeGraph();
  void printLand(list<Land *> *landsList);
  void printVertex(list<Vertex *> *vertexList);

  void makePlayer();
  void loadFiguresToPlayer(Player *);
  void loadRhoades(Player *);
  void loadCities(Player *);
  void loadTowns(Player *);
};
