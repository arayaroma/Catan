#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Label.hpp"
class Button
{
public:
	Button();
	~Button();

	void createButton(sf::RenderWindow& window, std::string, sf::RectangleShape name, sf::Vector2f posRec, sf::Color color, sf::Vector2f size, sf::Vector2f posLabel);
	

private:
	sf::Font font;
	sf::RectangleShape button;
	sf::Text text;

};

