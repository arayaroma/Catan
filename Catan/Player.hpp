#pragma once
#include "Game.hpp"

class Player : public Game{
private:
  std::string name;
  int score;

public:
  Player(){};
  Player(std::string, int);

  void setName(std::string);
  std::string getName();

  void setScore(int);
  int getScore();
};
