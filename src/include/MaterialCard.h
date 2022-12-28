#pragma once
#include "Card.h"
#include <string>
class MaterialCard: public Card{ 
    private:
    std::string type;
    std::string url;
	public:
    MaterialCard();
    MaterialCard(std::string typeCard, std::string urlCard);
    std::string getType();
    std::string getUrl();
    void setType();
    void setUrl();
}