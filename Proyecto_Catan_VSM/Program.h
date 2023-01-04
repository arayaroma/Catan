#pragma once
#include "Land.h"
#include "LandNode.h"
#include "List.h"
#include "Stack.h"
#include <iostream>
#include <string>
class Program {
private:
	int turn;
	List* lands = new List();
	Stack* cards = new Stack();
public:
	Program();
	void assemblyLand();
	void assignLand();
	void firstMove(std::string);
	void placeRoad();
	void placeTown();
	void play();
	void assignMaterial();
	void createCardStacks();
	void loadCards();
	void loadMaterialCards();
	void loadDevelopCards();
	void shuffleCard();
	int rollDice();
	void tradeMaterials();
	void build();
	void playDevelopCard();
};

