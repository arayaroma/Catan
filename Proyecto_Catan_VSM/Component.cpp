#include "Component.h"
using namespace std;

Component::Component() {}

void Component::setTypeClass(string t) {
	typeClass = t;
}

string Component::getTypeClass() {
	return typeClass;
}

string Component::getType() { return type; }
string Component::getUrl() { return url; }

void Component::setType(string typeLand) { type = typeLand; }
void Component::setUrl(string urlLand) { url = urlLand; }