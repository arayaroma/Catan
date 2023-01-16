#include "Label.hpp"

Label::Label() {}

Label::Label(const sf::String& text, const sf::Color& color,
	const sf::Font& font, sf::Uint32 style, unsigned int font_size,
	float pos_x, float pos_y) {
	this->text = text;
	this->color = color;
	this->font = font;
	this->style = style;
	this->font_size = font_size;
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->textInstance.setString(text);
	this->textInstance.setFillColor(color);
	this->textInstance.setFont(font);
	this->textInstance.setStyle(style);
	this->textInstance.setCharacterSize(font_size);
	this->textInstance.setPosition(pos_x, pos_y);
}

const sf::Text Label::getTextInstance() const { return this->textInstance; }