#pragma once
#include <iostream>
#include <string>

#define LAND "Land"
#define FIGURE "Figure"
#define CARD "Card"

class Component {
protected:
public:
		std::string url;
		std::string typeClass;
	Component();
	void setTypeClass(std::string t);
	std::string getTypeClass();

	void to_string();
};

