#include "Match.hpp"

Match::Match() {}

void Match::setName(const char *name) { this->name = name; }
const char *Match::getName() const { return this->name; }

void Match::setMatchID(int matchID) { this->matchID = matchID; }
int Match::getMatchID() const { return this->matchID; }