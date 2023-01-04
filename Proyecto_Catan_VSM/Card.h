#pragma once
#include <string>
class Card
{
private:
	std::string type;
	std::string url;
	std::string name;
public:
	Card();
	Card(std::string typeCard, std::string urlCard, std::string nameCard);
	std::string getType();
	std::string getUrl();
	std::string getName();
	void setType(std::string typeCard);
	void setUrl(std::string urlCard);
	void setName(std::string NameCard);
	void toString();
};

