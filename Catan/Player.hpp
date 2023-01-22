#pragma once
#include <string>
#include "Figures.hpp"
#include <list>
using std::list;
class Player  {
private:
  std::string name;
  int score;
  list<Town> towns;
  list<Road> roads;
  list<City> citys;
public:
  Player(){};
  Player(std::string, int);

  void setName(std::string);
  std::string getName();

  void setScore(int);
  int getScore();
};
