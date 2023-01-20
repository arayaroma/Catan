#pragma once
#include "Card.hpp"
#include "Land.hpp"
#include "Materials.hpp"
#include "ProgressCards.hpp"
#include "StructureGraph.hpp"
#include <unordered_map>

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

class DataStructures {
public:
	std::unordered_map<const char*, const char*> um_Paths;
	//LinkedList<Land> lands;
	//LinkedList<Town> townFigures;
	//LinkedList<City> cityFigures;
	//LinkedList<Road> roadFigures;
	//LinkedList<int> towns;

	//Stack<Clay>* clayCards = new Stack<Clay>();
	//Stack<Mineral>* mineralCards = new Stack<Mineral>();
	//Stack<Wheat>* wheatCards = new Stack<Wheat>();
	//Stack<Wood>* woodCards = new Stack<Wood>();
	//Stack<Wool>* woolCards = new Stack<Wool>();
	//Stack<Knight>* knightCards = new Stack<Knight>();
	//Stack<Progress>* progressCards = new Stack<Progress>();
	//Stack<VictoryPoints>* victoryPointCards = new Stack<VictoryPoints>();

	Card* specialCard[2];
	Graph graph;
	Land land;

public:
	DataStructures();

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
	//void assignTowns(Node<Land>*, int, int, int);
	//void assignTownsMiddleRow(Node<Land>*, int, int, int);
	//void assignTownsLastRows(Node<Land>*, int, int, int);
	void makeMaterialCard();
	void makeDevelopCard();
	void playDevelopCard();
	void makeFigures();
	void makeConstructionCostsCard();
	void makeSpecialCard();
	//void printVertexXY() { graph.vertexXY(); }
	void makeGraph();
	void makeVertexOwners();
};
