#pragma once
#include <string>
#include "Component.h"
class Figure : public Component {
private:
	std::string type;
	std::string url;

public:
	Figure() { setTypeClass(FIGURE); }
	Figure(std::string typeCard, std::string urlCard);
	std::string getType();
	std::string getUrl();
	void setType(std::string typeCard);
	void setUrl(std::string urlCard);
};

