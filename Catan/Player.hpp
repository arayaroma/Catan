#pragma once
#include "Figures.hpp"
#include <list>
#include <string>
#include "Cards.h"
using std::list;

class Player {
protected:
  string name;
  string color;
  int score;
  int turnNumber;
public:
  Player();
  Player(string, int, string);

  void setName(string);
  string getName() const;

  void setColor(string);
  string getColor() const;

  void setScore(int);
  int getScore() const;
  // Implementar metodos abstractos
  // 
  //figures
  list<Town*> *towns;
  list<Road*> *roads;
  list<City*> *citys;
  //carts
  list<Wool*> *woolCard;
  list<Wood*> *woodCard;
  list<Clay*> *clayCard;
  list<Mineral*> *mineralCard;
};
