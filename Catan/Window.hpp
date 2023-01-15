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

public:
	sf::RenderWindow *actualWindow;

public:
	Window(const Window&) = delete;

	static Window& getInstance() {
		static Window instance;
		return instance;
	}

	bool isMouseButtonPressedLeft();
	bool isClicked(int, int, int, int);

	void showCoordinates(sf::RenderWindow&);
	void goTitleView();
	void goAboutView();
	void goPlayView();
	bool isEscapePressed();

	void printResources(sf::RenderWindow&, std::string, int, int);
	void printMaterialCard(sf::RenderWindow&);
	void printImageTown(std::string, int, int);
	void printBoard(sf::RenderWindow&);
	void printTown(sf::RenderWindow&);

private:
	Window() {}
};
