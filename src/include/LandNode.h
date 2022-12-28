#pragma once
#include "Node.h"
#include "Land.h"
class LandNode: public Node{
    private:
    Land* info;
    public:
    LandNode(Land* );
    void setInfo(Land* );
	Land* getInfo();
};