#pragma once

#include "iostream" 
#include <string>

class Land {
private:
	std::string type;
	std::string url;
	/*std::string owner;
	std::string name;*/

public:
	Land();
	Land(std::string typeLand, std::string urlLand);
	std::string getType();
	std::string getUrl();
	void setType(std::string typeLand);
	void setUrl(std::string urlLand);
	void toString();
};

