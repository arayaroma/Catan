#include "TextBox.h"

TextBox::TextBox() {}
TextBox::TextBox(int size, sf::Color color, bool sel, sf::Vector2f position, sf::Vector2f sizeBorder, sf::Color colorBorder) {
	textBox.setCharacterSize(size);
	textBox.setFillColor(color); 
	
	border.setPosition(position);
	border.setSize(sizeBorder);
	border.setFillColor(colorBorder);
	


	isSelected = sel; 
	if (sel) {
		textBox.setString("_");
	}
	else {
		textBox.setString("");
	}
}
void TextBox::inputLogic(int charType) {

	if (charType != DELETE_KEY && charType != ENTER_KEY && charType != ESCAPE_KEY) {
		text << static_cast<char>(charType);
	}
	else if (charType == DELETE_KEY) {
		if (text.str().length() > 0) {
			deleteLastCharacter(); 
		}
	}
	textBox.setString(text.str() + "_"); 
}

void TextBox::deleteLastCharacter() {
	std::string t = text.str(); 
	std::string newT = ""; 
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	text.str(""); 
	text << newT; 
	textBox.setString(text.str()); 
}

void TextBox::serFont(sf::Font& font) {
	textBox.setFont(font); 
}
void TextBox::setPosition(sf::Vector2f pos) {
	textBox.setPosition(pos);
}
void TextBox::setLimit(bool tOf) {
	hasLimit = tOf; 
}
void TextBox::setLimit(bool tOf, int lim) {
	hasLimit = tOf;
	limit = lim; 
}

void TextBox::setSelected(bool sel) {
	isSelected = sel;
	if (!sel) {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++) {

			newT += t[i];
		}
		textBox.setString(newT);
	}
}

string TextBox::getText() {
	return text.str(); 
}
void TextBox::drawTo(sf::RenderWindow &window) 
{
	window.draw(border);
	window.draw(textBox);
}

void TextBox::typeOn(sf::Event input) {
	if (isSelected) {
		int charType = input.text.unicode;
		if (charType < 128) {

			if (hasLimit) {
				if (text.str().length() <= limit) {
					inputLogic(charType);
				}
				else if (text.str().length() > limit && charType== DELETE_KEY){
					deleteLastCharacter();
				}
			}
			else {
				inputLogic(charType);
			}
		}
	}
}


bool TextBox::isMouseOver(sf::RenderWindow& window) {

	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float btnPosX = border.getPosition().x;
	float btnPosY = border.getPosition().y;

	float btnxPosWidth = border.getPosition().x + border.getGlobalBounds().width;
	float btnyPosHeight = border.getPosition().y + border.getGlobalBounds().height;

	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY>btnPosY) {

		return true;
	}
	return false;

}
