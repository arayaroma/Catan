#pragma once
#include "Card.hpp"

/*
    6x Progress
    To be shopped:
    1 Mineral + 1 Wool + 1 Wheat
*/

class Progress : public Card {
private:
    std::string m_Url;

public:
    Progress() {}
    Progress(std::string url) : m_Url(url) {}
};
