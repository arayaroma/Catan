#pragma once
#include "Button.hpp"
#include "DataStructures.hpp"
#include "FlowController.hpp"
#include "Label.hpp"
#include "Land.hpp"
#include "LinkedList.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

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

	void printHexagon(std::string, int x, int y);
	void printMaterialCard();
	void printImageTown(std::string url, int x, int y);
	void printBoard();
	void printTown();
	void Image(std::string);

private:
	Window() {}
};
