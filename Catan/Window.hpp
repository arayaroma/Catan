#pragma once
#include "Button.h"
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
	sf::Event event;

public:
	Window(const Window&) = delete;

	static Window& getInstance() {
		static Window instance;
		return instance;
	}

	void showCoordinates(sf::RenderWindow&);
	bool isMouseOverAbout();
	void goTitleView();
	void goAboutView();
	void goPlayView();
	bool goBack(sf::RenderWindow& window);

	void printResources(sf::RenderWindow& window, std::string, int , int );
	void printMaterialCard(sf::RenderWindow& window);
	void printImageTown(std::string url, int x, int y);
	void printBoard(sf::RenderWindow& window);
	void printTown(sf::RenderWindow& window);
	void Image(std::string);


	void crateButton( sf::RenderWindow& window);

	

private:
	Window() {}
};
