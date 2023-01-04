#pragma once
#include "Land.h"
class LandNode 
{
private:
	Land* infoLand;
	LandNode* next;
	LandNode* previous;
public:
	LandNode(Land* i);
	LandNode();
	void setInfo(Land* i);
	Land* getInfo();
	void setNext(LandNode* next);
	LandNode* getNext();
	void setPrevious(LandNode* previous);
	LandNode* getPrevious();
};

