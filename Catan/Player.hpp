#pragma once
#include "Game.hpp"
#include "Figures.hpp"
class Player : public Game {
private:
  std::string name;
  int score;
  LinkedList<Town> towns;
  LinkedList<Road> roads;
  LinkedList<City> citys;
public:
  Player(){};
  Player(std::string, int);

  void setName(std::string);
  std::string getName();

  void setScore(int);
  int getScore();
};
