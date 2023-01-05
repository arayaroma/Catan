#include "Component.h"
using namespace std;

Component::Component() {}

void Component::setTypeClass(string t) {
	typeClass = t;
}

string Component::getTypeClass() {
	return typeClass;
}

void Component::to_string() {
	std::cout << this->typeClass << " " << this->url << " ";
}