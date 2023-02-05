#pragma once
#include "Cards.hpp"
#include "Figures.hpp"
#include <list>
#include <string>
#include "DevelopCards.hpp"
using std::list;

class Player {
protected:
  string name;
  string color;
  int score;
  int turnNumber;
  int townFirstTurn = 0;
  bool firstTurnFinished = false;
public:
  Player();
  Player(string, int, string);

  void setFirstTurnFinished(bool band) { firstTurnFinished = band; }
  bool getFirstTurnFinished() { return this->firstTurnFinished; }
  void setTownFirstTurn(int it) { townFirstTurn += it; }
  int getTownFirstTurn() { return this->townFirstTurn; }
  void setName(string);
  string getName() const;

  void setColor(string);
  string getColor() const;

  void setScore(int);
  int getScore() const;
  // Implementar metodos abstractos
  //
  // figures
  list<Town *> *towns;
  list<Road *> *roads;
  list<City *> *citys;
  // carts
  list<Wool *> *woolCard;
  list<Wood *> *woodCard;
  list<Clay *> *clayCard;
  list<Mineral *> *mineralCard;
  list<Wheat*>* wheatlCard;

  list<Progress*>* progressCards;
  list<Knight*>* knightCards;
  list<VictoryPoints*>* victoryPointsCards;
};
