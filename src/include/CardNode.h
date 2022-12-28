#pragma once
#include "Node.h"
#include "Card.h"
class CardNode: public Node{
    private:
    Card* info;
    public:
    CardNode(Card* );
    void setInfo(Card* );
	Card* getInfo();
};