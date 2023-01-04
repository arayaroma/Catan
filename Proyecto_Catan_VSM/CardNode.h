#pragma once
#include "Card.h"
class CardNode {
protected:
	CardNode* next;
	CardNode* previous;
	Card* infoCard;
public:
	CardNode();
	void setNext(CardNode* next);
	CardNode* getNext();
	void setPrevious(CardNode* previous);
	CardNode* getPrevious();
	CardNode(Card* i);
	void setInfo(Card* i);
	Card* getInfo();

};

