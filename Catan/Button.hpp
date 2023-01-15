#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Button{
public:
	Button();
	Button(std::string, sf::Vector2f, int, sf::Color, sf::Color);

	void setFont(sf::Font&);
	void setBackColor(sf::Color);
	void setTextColor(sf::Color);
	void setPosition(sf::Vector2f);
	void drawTo(sf::RenderWindow&);
	bool  isMouseOver(sf::RenderWindow&);


private:
	sf::RectangleShape rectangle;
	sf::Text text;
	int mouse_x, mouse_y;
	float rectangle_x, rectangle_y;
	float rectangle_width, rectangle_height;
};

