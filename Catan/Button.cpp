#include "Button.hpp"

Button::Button() {

}

Button::Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor) {

	text.setString(t);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);

	button.setSize(size);
	button.setFillColor(bgColor);
}

void Button::setFont(sf::Font& font) {

	text.setFont(font);
}

void Button::setBackColor(sf::Color color) {

	button.setFillColor(color);
}
void Button::setTextColor(sf::Color color) {

	text.setFillColor(color);
}

void Button::setPosition(sf::Vector2f pos) {

	button.setPosition(pos);
	float xPos = (pos.x + button.getGlobalBounds().width / 3) - (text.getGlobalBounds().width / 3);
	float yPos = (pos.y + button.getGlobalBounds().height / 3) - (text.getGlobalBounds().height / 3);
	text.setPosition({ xPos,yPos });
}


void Button::setPosition2(sf::Vector2f pos) {

	button.setPosition(pos);
	float xPos = (pos.x + button.getGlobalBounds().width / 5) - (text.getGlobalBounds().width / 5);
	float yPos = (pos.y + button.getGlobalBounds().height / 5) - (text.getGlobalBounds().height / 5);
	text.setPosition({ xPos,yPos });
}
void Button::setPosition3(sf::Vector2f pos) {

	button.setPosition(pos);
	float xPos = (pos.x + button.getGlobalBounds().width / 7) - (text.getGlobalBounds().width / 7);
	float yPos = (pos.y + button.getGlobalBounds().height / 5) - (text.getGlobalBounds().height / 5);
	text.setPosition({ xPos,yPos });
}

 
void Button::drawTo(sf::RenderWindow& window) {
	window.draw(button);
	window.draw(text);
}

bool  Button::isMouseOver(sf::RenderWindow& window) {

	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float btnPosX = button.getPosition().x;
	float btnPosY = button.getPosition().y;

	float btnxPosWidth = button.getPosition().x + button.getGlobalBounds().width;
	float btnyPosHeight = button.getPosition().y + button.getGlobalBounds().height;

	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY>btnPosY) {

		return true;
	}
	return false;

}

