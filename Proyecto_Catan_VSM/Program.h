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
	void play();
	void build();
	void tradeMaterials();
	void assemblyLand();
	void playDevelopCard();
};

