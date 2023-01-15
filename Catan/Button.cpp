#include "Button.hpp"

Button::Button() {}

Button::Button(std::string message, sf::Vector2f size, int charSize,
	sf::Color bgColor, sf::Color textColor) {

	text.setString(message);
	text.setCharacterSize(charSize);
	rectangle.setSize(size);
	rectangle.setFillColor(bgColor);
}

void Button::setFont(sf::Font& font) { text.setFont(font); }

void Button::setBackColor(sf::Color color) { rectangle.setFillColor(color); }

void Button::setTextColor(sf::Color color) {
}

void Button::setPosition(sf::Vector2f pos) {

	rectangle.setPosition(pos);
	float xPos = (pos.x + rectangle.getLocalBounds().width / 2) -
		(text.getLocalBounds().width / 2);
	float yPos = (pos.y + rectangle.getLocalBounds().height / 2) -
		(text.getLocalBounds().height / 2);
	text.setPosition({ xPos, yPos });
}

void Button::drawTo(sf::RenderWindow& window) {
	window.draw(rectangle);
	window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow& window) {

	mouse_x = sf::Mouse::getPosition(window).x;
	mouse_y = sf::Mouse::getPosition(window).y;

	rectangle_x = rectangle.getPosition().x;
	rectangle_y = rectangle.getPosition().y;

	rectangle_width = rectangle.getPosition().x + rectangle.getLocalBounds().width;
	rectangle_height = rectangle.getPosition().y + rectangle.getLocalBounds().height;

	if (mouse_x < rectangle_width && mouse_x > rectangle_x && mouse_y < rectangle_height &&
		mouse_y > rectangle_y)
		return true;
	return false;
}
