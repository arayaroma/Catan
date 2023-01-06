#pragma once
#include <iostream>
#include <string>
#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Component.hpp"
#include "Land.hpp"
#include "Card.hpp"
class Program {
private:
	int turn;
	std::string urlKnight = "images/knight_cards/knight_";
	std::string urlEnd = "_card.png";
	std::string urlProgress = "images / develop_cards / develop_";
	std::string urlVictoryPoint = "Images / victory_points_cards / victory_point_";
	LinkedList lands;
	Stack* woodCard = new Stack();
	Stack* knightCards = new Stack();
	Stack* progressCard = new Stack();
	Stack* victoryPointCard = new Stack();
	Stack* woolCard = new Stack();
	Stack* cerealCard = new Stack();
	Stack* clayCard = new Stack();
	Stack* mineralCard = new Stack();
public:
	Program();
	void play();
	void build();
	void tradeMaterials();
	void assemblyLand();
	void makeMaterialCard();
	void makeDevelopCard();
	void playDevelopCard();
};
