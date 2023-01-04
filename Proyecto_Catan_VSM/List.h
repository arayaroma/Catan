#pragma once
#include "LandNode.h"
#include <string>
class List  {
private:
	LandNode* aux;
	LandNode* head;
	LandNode* end;
public:
	void add(LandNode* newLandNode);
	bool deleteNode(LandNode* LandNode);
	bool isEmpty();
	void print();
};


