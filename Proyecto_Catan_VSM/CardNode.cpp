#include "CardNode.hpp"

CardNode::CardNode() { this->next = NULL; }

CardNode::CardNode(Component* data) { this->data = data; this->next = next; }

void CardNode::set_data(Component* data) { this->data = data; }
Component* CardNode::get_data() { return this->data; }

void CardNode::set_next(CardNode* next) { this->next = next; }
CardNode* CardNode::get_next() {return this->next; }
