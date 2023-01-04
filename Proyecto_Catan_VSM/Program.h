#pragma once
#include "Land.h"
#include "List.h"
#include "Stack.h"
#include <iostream>
#include <string>
class Program {
private:
	int turn;
	List<Land> lands{};
	Stack<Card> cards;
public:
	Program();
	void play();
	void build();
	void tradeMaterials();
	void assemblyLand();
	void playDevelopCard();
};

