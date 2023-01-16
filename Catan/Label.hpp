#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Label {
protected:
	sf::Text textInstance;
	sf::String text;
	float pos_x, pos_y;
	unsigned int font_size;
	sf::Color color;
	sf::Font font;
	sf::Uint32 style;

public:
	Label();
	Label(const sf::String&, const sf::Color&, const sf::Font&, sf::Uint32,
		unsigned int, float, float);
	const sf::Text getTextInstance() const;
};