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
	list<Progress*>::iterator progressIterator;
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
	void KnightButtonClicked(sf::Event event);
	void ProgressButtonClicked(sf::Event event);
	void VictoryButtonClicked(sf::Event event);
	void BuyButtonPressed(sf::Event event);
	sf::Event eventTest;
	Button buy, p, victory, progress,knight;

	bool isKnightButtonClicked = false;
	bool isProgressButtonClicked = false;
	bool isVictoryButtonClicked = false;
	bool isBuyClicked = false;

};
