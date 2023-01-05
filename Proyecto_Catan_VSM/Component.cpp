#include "Component.h"
Component::Component() {}
using namespace std;
void Component::setTypeClass(string t) {
	typeClass = t;
}
string Component::getTypeClass() {
	return typeClass;
}