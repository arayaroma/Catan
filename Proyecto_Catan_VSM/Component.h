#pragma once
#include <iostream>
#include <string>

#define LAND "Land"
#define FIGURE "Figure"
#define CARD "Card"

class Component {
protected:
	std::string url;
	std::string type;
public:
	std::string typeClass;
	Component();
	void setTypeClass(std::string t);
	std::string getTypeClass();
	std::string getType();
	std::string getUrl();
	void setType(std::string typeCard);
	void setUrl(std::string urlCard);
	virtual void to_string()=0;
};

