#pragma once
#include "Game.hpp"
#include "Player.hpp"
class Match : public Game {
private:
  const char *name;
  int matchID;
  Player *players;

public:
  Match();

  void setName(const char *);
  const char *getName() const;

  void setMatchID(int);
  int getMatchID() const;

};
