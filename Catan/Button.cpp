#include "Button.hpp"

Button::Button() {
	font.loadFromFile("mononoki.ttf");
}

Button:: ~Button() {}

void Button::createButton(sf::RenderWindow& window, std::string text, 
	sf::RectangleShape name, sf::Vector2f pos, 
	sf::Color color, sf::Vector2f size, sf::Vector2f posLabel) {

	Label* title = new Label(text, sf::Color::Black, font, 
		sf::Text::Bold, 20, posLabel.x, posLabel.y);
	name.setPosition(pos);
	name.setFillColor(color);
	name.setSize(size);
	window.draw(name);
	window.draw(title->getTextInstance());
}