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
	Game game; 


public:
	void goView() override;

private:
	void loadView() override;
	void drawView() override;

public:
	
	void printImages(string imagePath, double posX, double posY);
	void loadMaterialPaths();

	void showCoordinates(sf::Event event);
	void createButtons();
	void drawButton(Button& btm);

	void clayButtonClicked(sf::Event event);
	void wheatButtonClicked(sf::Event event);
	void woodButtonClicked(sf::Event event);
	void woolButtonClicked(sf::Event event);
	void mineralButtonClicked(sf::Event event);
	void tradeButtonClicked(sf::Event event);
	sf::Event eventTest;
	Button buy, p,clay, wheat, wood, wool, mineral , trade;

	bool isCLayButtonClicked = false;
	bool isWheatButtonClicked = false;
	bool isWoodButtonClicked = false;
	bool isWoolButtonClicked = false;
	bool isMineralButtonClicked = false;
	bool isTradeClicked = false;

};

