#pragma once
#include "Card.hpp"
#include "Land.hpp"
#include "LinkedList.hpp"
#include "Materials.hpp"
#include "ProgressCards.hpp"
#include "Stack.hpp"
#include "StructureGraph.hpp"
#include <unordered_map>

class DataStructures {
public:
	std::unordered_map<const char*, const char*> um_Paths;
	LinkedList<Land> lands;
	LinkedList<Town> townFigures;
	LinkedList<City> cityFigures;
	LinkedList<Road> roadFigures;
	LinkedList<int> towns;

	Stack<Clay>* clayCards = new Stack<Clay>();
	Stack<Mineral>* mineralCards = new Stack<Mineral>();
	Stack<Wheat>* wheatCards = new Stack<Wheat>();
	Stack<Wood>* woodCards = new Stack<Wood>();
	Stack<Wool>* woolCards = new Stack<Wool>();
	Stack<Knight>* knightCards = new Stack<Knight>();
	Stack<Progress>* progressCards = new Stack<Progress>();
	Stack<VictoryPoints>* victoryPointCards = new Stack<VictoryPoints>();

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
	void assignTowns(Node<Land>*, int, int, int, int, int, int);
	void assignTownsMiddleRow(Node<Land>*, int, int, int, int, int, int);
	void assignTownsLastRows(Node<Land>*, int, int, int, int, int, int);
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
