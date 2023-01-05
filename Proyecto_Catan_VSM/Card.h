#pragma once
#include <string>
#include "Component.h"
class Card : public Component
{
private:
	std::string name;
public:
	Card() { setTypeClass(CARD); }
	Card(std::string typeCard, std::string urlCard, std::string nameCard);
	std::string getName();
	void setName(std::string NameCard);
	void to_string();
};

