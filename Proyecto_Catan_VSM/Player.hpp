#pragma once
#include <iostream>

class Player {
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
