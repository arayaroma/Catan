#pragma once
#include "Button.hpp"
#include "Label.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include "Game.hpp"
#include <iostream>
#include "Materials.hpp"

class TradeView:View
{

public:
	//iterador
	list<Clay*>::iterator knightIterator;
	list<Wood*>::iterator iteratorIterator;
    list<Wool*>::iterator victoryIterator;
	list<Wheat*>::iterator victoryIterator;
	list<Mineral*>::iterator victoryIterator;

public:
	void goView() override;

private:
	void loadView() override;
	void drawView() override;

public:
	Game game;
	void printImages(string imagePath, double posX, double posY);
	void loadMaterialPaths();

	void showCoordinates(sf::Event event);
	void createButtons();
	void drawButton(Button& btm);

	sf::Event eventTest;
	Button buy, p;



};

