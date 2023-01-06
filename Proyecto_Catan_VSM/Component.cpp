#include "Component.hpp"
using namespace std;

Component::Component() {}

void Component::setTypeClass(string type) { this->type = type; }
string Component::getTypeClass() { return type; }

void Component::setType(string type) { this->type = type; }
string Component::getType() { return type; }

void Component::setUrl(string url) { this->url = url; }
string Component::getUrl() { return url; }