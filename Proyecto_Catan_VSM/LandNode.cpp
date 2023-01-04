#include "LandNode.h"
LandNode::LandNode(Land* i) {
	infoLand = i;
}
LandNode::LandNode() {
	next = NULL;
	previous = NULL;
}
void LandNode::setNext(LandNode* nextLandNode) { next = nextLandNode; }
LandNode* LandNode::getNext() { return next; }

void LandNode::setPrevious(LandNode* previousLandNode) { previous = previousLandNode; }
LandNode* LandNode::getPrevious() { return previous; }

void LandNode::setInfo(Land* i) { infoLand = i; }
Land* LandNode::getInfo() { return infoLand; }
