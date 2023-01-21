#pragma once
#include "StructureGraph.hpp"
#include "ProgressCards.hpp"
#include "Materials.hpp"
#include "Card.hpp"
#include "Land.hpp"
#include "Figures.hpp"
#include <unordered_map>
#include <string>
#include <list>
#include <stack>
using std::string, std::unordered_map, std::list, std::stack;

/*
  Points:
  If a player has 10 points wins.

  If a player has more than 5 roads consecutive it gets:
  Biggest Path Card - II Points.
  However if someone have more than the highest roads player number
  then inmediatly it gets the card.

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
	unordered_map<string, string> imagePaths;
	Graph graph;
	Land land;

	list<int> *townsID;
	list<Town> *towns;

	list<City> *cities;
	list<Road> *roads;
	list<Land*> *lands;

	Card* specialCard[2];

	stack<Knight> *knightCards = new stack<Knight>();
	stack<Progress> *progressCards = new stack<Progress>();
	stack<VictoryPoints> *victoryPointCards = new stack<VictoryPoints>();

	stack<Clay> *clayCards = new stack<Clay>;
	stack<Mineral> *mineralCards = new stack<Mineral>;
	stack<Wheat> *wheatCards = new stack<Wheat>;
	stack<Wood> *woodCards = new stack<Wood>;
	stack<Wool> *woolCards = new stack<Wool>;

public:
	Game();

	void loadMaps();
	void loadSpecialCards();
	void loadProgressPaths();
	void loadTilesPaths();

	void loadStacks();

	void play();
	void build();

	void tradeMaterials();
	void loadLands();

	void assignTownsToLand();
	void assignTowns(Land, int, int, int);
	void assignTownsMiddleRow(Land, int, int, int);
	void assignTownsLastRows(Land, int, int, int);
	void makeMaterialCard();
	void makeDevelopCard();
	void playDevelopCard();
	void makeFigures();
	void makeConstructionCostsCard();
	void makeSpecialCard();
	void printVertexXY() { graph.vertexXY(); }
	void makeGraph();
	void makeVertexOwners();
};
