#pragma once
#include <string>
class Land(){
    private:
    std::string type;
    std::string url;
    std::string owner;
    std::string name;
	public:
    Land();
    Land(std::string typeCard, std::string urlCard);
    std::string getType();
    std::string getUrl();
    void setType();
    void setUrl(); 
}