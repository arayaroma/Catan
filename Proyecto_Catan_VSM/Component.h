#pragma once
#include <string>
#define LAND "Land"
#define FIGURE "Figure"
#define CARD "Card"
class Component
{
protected:
		std::string url;
		std::string typeClass;
public:
	void setTypeClass(std::string t);
	std::string getTypeClass();
	Component();
};

