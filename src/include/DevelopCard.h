#include "Card.h"
#include <string>
 class DevelopCard: public Card{ 
    private:
    std::string type;
    std::string url;
	public:
    DevelopCard();
    DevelopCard(std::string typeCard, std::string urlCard);
    std::string getType();
    std::string getUrl();
    void setType();
    void setUrl();
}