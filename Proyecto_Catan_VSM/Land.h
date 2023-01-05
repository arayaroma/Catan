#pragma once

#include "iostream" 
#include <string>
#include "Component.h"
class Land : public Component{
private:
	std::string type;
	std::string url;
	/*std::string owner;
	std::string name;*/

public:
	Land() { setTypeClass(LAND); this->type = ""; this->url = ""; }
	Land(std::string typeLand, std::string urlLand);
	Land(Component* land) {}
	std::string getType();
	std::string getUrl();
	void setType(std::string typeLand);
	void setUrl(std::string urlLand);
	void toString();
};

