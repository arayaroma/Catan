#pragma once
#include "Card.hpp"

/*
    14x Knights
    To be shopped:
    1 Mineral + 1 Wool + 1 Wheat
*/

class Knight : public Card {

private:
    std::string m_Url;

public:
    Knight() {}
  Knight(std::string url) : m_Url(url) {}
};
