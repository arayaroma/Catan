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
	void to_string();
};

