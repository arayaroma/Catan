#pragma once
#include "Cards.hpp"
#include "DevelopCards.hpp"
#include "Figures.hpp"
#include <list>
#include <string>

using std::list;

class Player {
public:
  std::string to_string() const {
    return name + delimiter + color + delimiter + std::to_string(score) +
           delimiter + std::to_string(turnNumber) + delimiter +
           std::to_string(townFirstTurn) + delimiter +
           std::to_string(progressDiscovery) + delimiter +
           bool_to_string(firstTurnFinished);
  }

  std::string to_string(const std::list<Town *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::list<Road *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }
  std::string to_string(const std::list<City *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::list<Clay *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::list<Mineral *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::list<Wheat *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::list<Wood *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::list<Wool *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

protected:
  string name;
  string color;
  int score;
  int turnNumber;
  int townFirstTurn = 0;
  int progressDiscovery = 2;
  bool firstTurnFinished = false;
  bool isTheLargestArmy = false;
public:
  list<Town *> *towns;
  list<Road *> *roads;
  list<City *> *citys;

  list<Clay *> *clayCard;
  list<Mineral *> *mineralCard;
  list<Wheat *> *wheatlCard;
  list<Wood *> *woodCard;
  list<Wool *> *woolCard;

  list<Progress *> *progressCards;
  list<Knight *> *knightCards;
  list<VictoryPoints *> *victoryPointsCards;

  Progress *progressMonopoly;

public:
  Player();
  Player(string, int, string);

  void setName(string);
  string getName() const;

  void setColor(string);
  string getColor() const;

  void setScore(int);
  int getScore() const;

  void setFirstTurnFinished(bool band) { firstTurnFinished = band; }
  bool getFirstTurnFinished() { return this->firstTurnFinished; }

  void setTheLargestArmy(bool band) { this->isTheLargestArmy = band; }
  bool getTheLargestArmy() { return this->isTheLargestArmy; }

  void setTownFirstTurn(int it) { townFirstTurn += it; }
  int getTownFirstTurn() { return this->townFirstTurn; }

  void setProgressDiscovery(int n) { this->progressDiscovery = n; }
  int getProgressDiscovery() { return this->progressDiscovery; }
  void restProgressDiscovery(int n) { this->progressDiscovery -= n; }
};
