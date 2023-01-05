#include "CardNode.h"

CardNode::CardNode() { this->next = NULL; }

CardNode::CardNode(Card data) { this->data = data; this->next = next; }

void CardNode::set_data(Card data) { this->data = data; }
Card CardNode::get_data() { return this->data; }

void CardNode::set_next(CardNode* next) { this->next = next; }
CardNode* CardNode::get_next() {return this->next; }
