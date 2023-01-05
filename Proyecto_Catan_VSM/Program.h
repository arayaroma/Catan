#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Stack.h"
#include "Land.h"

class Program {
private:
	int turn;
	LinkedList lands;
	Stack cards;
public:
	Program();
	void play();
	void build();
	void tradeMaterials();
	void assemblyLand();
	void playDevelopCard();
};

