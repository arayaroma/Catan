#pragma once
#include "Figures.hpp"
#include <list>
#include <string>
using std::list;

class Player {
protected:
  string name;
  string color;
  int score;
  int turnNumber;

  list<Town> towns;
  list<Road> roads;
  list<City> citys;

public:
  Player();
  Player(string, int);

  void setName(string);
  string getName() const;

  void setColor(string);
  string getColor() const;

  void setScore(int);
  int getScore() const;
  // Implementar metodos abstractos
};
