#pragma once
#include "Button.hpp"
#include "Label.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include "Game.hpp"
#include <iostream>
class BuyView : public View
{
public:

	list<Knight*>::iterator knightIterator;
	list<Progress*>::iterator iteratorIterator;
	list<VictoryPoints*>::iterator victoryIterator;

public:
	void goView() override;

private:
	void loadView() override;
	void drawView() override;

public:
	Game game; 
	void printImages(string imagePath, double posX, double posY);
	void loadProgressPaths(); 
	void loadKnightPaths();
	void loadVictoryPointsPaths();
	void showCoordinates(sf::Event event);

	void createButtons(); 
	void drawButton(Button& btm);
	sf::Event eventTest;
	Button buy, p;



};

