#include "Component.hpp"

Component::Component() {}

void Component::setTypeClass(std::string type) { this->type = type; }
std::string Component::getTypeClass() { return type; }

void Component::setType(std::string type) { this->type = type; }
std::string Component::getType() { return type; }

void Component::setUrl(std::string url) { this->url = url; }
std::string Component::getUrl() { return url; }