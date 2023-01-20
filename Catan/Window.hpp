#pragma once
#include "Button.hpp"
#include "DataStructures.hpp"
#include "FlowController.hpp"
#include "Label.hpp"
#include "Land.hpp"
#include "LinkedList.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colors.hpp"

class Window {
private:
	sf::Font font;
	Button Prueba;
	Button btnTrade;
	Button btnBuy;
	Button btnTurns;
	Button btnClose;
	Button btnOpcional1;
	Button btnOpcional2;

	sf::RectangleShape prueba;
	sf::RectangleShape trade;
	sf::RectangleShape buy;
	sf::RectangleShape Turnos;
	sf::RectangleShape close2;
	sf::RectangleShape opcional1;
	sf::RectangleShape opcional2;

	DataStructures dataStructures;
public:
	Window(const Window&) = delete;

	static Window& getInstance() {
		static Window instance;
		return instance;
	}

	void showCoordinates(sf::RenderWindow&);
	void goTitleView();
	void goAboutView();
	void goPlayView();
	bool goBack(sf::RenderWindow&);

	void printResources(sf::RenderWindow&, std::string, int, int);
	void printMaterialCard(sf::RenderWindow&);
	void printImageTown(std::string, int, int);
	void printBoard(sf::RenderWindow&);
	void printTown(sf::RenderWindow&);
	void updateDisplay();
	void loadStartButtons();
	void loadGameButtons();

private:
	Window() {}
};