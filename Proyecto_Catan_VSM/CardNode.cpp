#include "CardNode.h"
#include <cstddef>
CardNode::CardNode(Card* i) {
	infoCard = i;
}
CardNode::CardNode() {
	next = NULL;
	previous = NULL;
}
void CardNode::setNext(CardNode* nextCardNode) { next = nextCardNode; }
CardNode* CardNode::getNext() { return next; }

void CardNode::setPrevious(CardNode* previousCardNode) { previous = previousCardNode; }
CardNode* CardNode::getPrevious() { return previous; }

void CardNode::setInfo(Card* i) { infoCard = i; }
Card* CardNode::getInfo() { return infoCard; }
