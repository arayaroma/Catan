#pragma once
#include <string>
 class Figure(){
    private:
    std::string type;
    std::string url;
	public:
    Figure();
    Figure(std::string typeCard, std::string urlCard);
    std::string getType();
    std::string getUrl();
    void setType();
    void setUrl(); 
}