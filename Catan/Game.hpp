#pragma once
#include "Card.hpp"
#include "DevelopCards.hpp"
#include "Figures.hpp"
#include "Land.hpp"
#include "Materials.hpp"
#include "Player.hpp"
#include "StructureGraph.hpp"
#include <iostream>
#include <list>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using std::list;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

/*
  Points:
  If a player has 10 points wins.

  If a player has more than 5 roads consecutive it gets:
  Biggest Path Card - II Points.
  However if someone have more than the highest roads player number
  then immediately it gets the card.

  Knight Cards
  If a player has at least 3 Knight cards, it gets:
  Biggest Army Card - II Points.

  Thief
  If a player gets 7 from the dice, nobody get materials.

  All player that has more than 7 cards of materials, must
  give those cards in the stacks. With even it rounds to down
  like (if a player has 9 cards, it must give 4 cards).

  Move the thief -> Method
  The player can move the Thief wherever it wants
  Then the player stoles a card of material to a player
  that has a Town or a City in that Tile, if there is more
  than one player, the thief chooses which.

  If the dice rolls the number where the thief stands, the players
  that has towns or cities in those numbers get no material, and the
  thief stands in the same place.
*/

class Game {

public:
  std::string to_string() const {
    return matchName + delimiter + endUrl + delimiter +
           std::to_string(matchId) + delimiter +
           bool_to_string(isNumbersLandsSet) + delimiter + graph.to_string() +
           delimiter + std::to_string(vertexId) + delimiter +
           std::to_string(vertexJump) + delimiter + std::to_string(graphNodes) +
           delimiter + to_string(imagePaths) + delimiter + to_string(*players) +
           delimiter + to_string(*townsList) + delimiter +
           to_string(*citiesList) + delimiter + to_string(*roadsList) +
           delimiter + to_string(*landsList) + delimiter +
           to_string(*vertexesList) + delimiter + to_string(*knightCards) +
           delimiter + to_string(*progressCards) + delimiter +
           to_string(*victoryPointCards) + delimiter + to_string(*clayCards) +
           delimiter + to_string(*mineralCards) + delimiter +
           to_string(*wheatCards) + delimiter + to_string(*woodCards) +
           delimiter + to_string(*woolCards) + delimiter +
           to_string(landsNumbers);
  }

private:
  string matchName;
  string endUrl;
  int matchId;
  bool isNumbersLandsSet = false;

public:
  Graph graph;
  int vertexId, vertexJump;
  int graphNodes = 54;

  void setGraph(Graph);
  Graph getGraph() const;

  unordered_map<string, string> imagePaths;
  void setImagePaths(unordered_map<string, string>);
  unordered_map<string, string> getImagePaths() const;

  list<Player *> *players;
  list<Player *>::iterator playerIterator;
  void setPlayersList(list<Player *> *);
  list<Player *> *getPlayersList() const;

  // no se carga en goView
  list<Town *> *townsList;
  list<Town *>::iterator townIterator;
  void setTownsList(list<Town *> *);
  list<Town *> *getTownsList() const;

  // no se carga en goView
  list<City *> *citiesList;
  list<City *>::iterator cityIterator;
  void setCitiesList(list<City *> *);
  list<City *> *getCitiesList() const;

  // no se carga
  list<Road *> *roadsList;
  list<Road *>::iterator roadIterator;
  void setRoadsList(list<Road *> *);
  list<Road *> *getRoadsList() const;

  list<Land *> *landsList;
  list<Land *>::iterator landIterator;
  void setLandsList(list<Land *> *);
  list<Land *> *getLandsList() const;

  // obsoleto
  list<Vertex *> *vertexesList;
  void setVertexesList(list<Vertex *> *);
  list<Vertex *> *getVertexesList() const;

  list<Knight *> *knightCards = new list<Knight *>();
  void setKnightCards(list<Knight *> *);
  list<Knight *> *getKnightCards() const;

  list<Progress *> *progressCards = new list<Progress *>();
  void setProgressCards(list<Progress *> *);
  list<Progress *> *getProgressCards() const;

  list<VictoryPoints *> *victoryPointCards = new list<VictoryPoints *>();
  void setVictoryPointsCards(list<VictoryPoints *> *);
  list<VictoryPoints *> *getVictoryPointsCards() const;

  stack<Clay *> *clayCards = new stack<Clay *>;
  void setClayCards(stack<Clay *> *);
  stack<Clay *> *getClayCards() const;

  stack<Mineral *> *mineralCards = new stack<Mineral *>;
  void setMineralCards(stack<Mineral *> *);
  stack<Mineral *> *getMineralCards() const;

  stack<Wheat *> *wheatCards = new stack<Wheat *>;
  void setWheatCards(stack<Wheat *> *);
  stack<Wheat *> *getWheatCards() const;

  stack<Wood *> *woodCards = new stack<Wood *>;
  void setWoodCards(stack<Wood *> *);
  stack<Wood *> *getWoodCards() const;

  stack<Wool *> *woolCards = new stack<Wool *>;
  void setWoolCards(stack<Wool *> *);
  stack<Wool *> *getWoolCards() const;

  vector<int> landsNumbers;
  void setLandNumbers(vector<int>);
  vector<int> getLandNumbers() const;

public:
  Game();

  void createGraphVertex();
  void makeGraph();
  void printVertex(list<Vertex *> *);

  void loadMaps();
  void loadLands();
  void loadDessert(int landId);
  void loadMountain(int landId);
  void loadField(int landId);
  void loadGrass(int landId);
  void loadForest(int landId);
  void swap(Land* a, Land* b);
  void loadBrick(int landId);
  void loadTilesPaths();
  void loadSpecialCards();
  void loadProgressPaths();
  void loadTowns(Player *);
  void loadRoades(Player *);
  void loadCities(Player *);
  void loadFiguresToPlayer(Player *, int);

  void assignTownsToLand();
  void assignTowns(Land *, int, int, int);
  void assignTownsMiddleRow(Land *, int, int, int);
  void assignTownsLastRows(Land *, int, int, int);

  void makePlayer();
  void makeFigures();
  void makeSpecialCard();
  void makeDevelopCard();
  void makeMaterialCard();

  void printVertexXY() { graph.vertexXY(); }
  void printLand(list<Land *> *);

  void loadLandsNumbers();
  void randomizeLandsNumbers();
  vector<int> getLandsNumbersRandomized();
  void printLandsNumbers(vector<int> const &);

  void setNumbersToLands(list<Land *> *);
  void printDiceNumbersInLands();

  void shuffleLandList();

  // unordered_map -> to_string
  std::string
  to_string(const std::unordered_map<std::string, std::string> &map) const {
    std::stringstream ss;
    ss << "{";
    for (const auto &kv : map) {
      ss << "\"" << kv.first << "\":\"" << kv.second << "\",";
    }
    ss << "}";
    return ss.str();
  }

  // unordered_map -> from_string
  std::unordered_map<std::string, std::string>
  from_string(const std::string &str) {
    std::unordered_map<std::string, std::string> map;
    std::stringstream ss(str);

    // Remove the initial '{' character
    ss.ignore();

    std::string kv;
    while (std::getline(ss, kv, ',')) {
      std::string key, value;
      std::stringstream kv_stream(kv);

      // Remove the quotes from the key
      kv_stream.ignore();
      std::getline(kv_stream, key, '\"');

      // Remove the ':' character
      kv_stream.ignore();

      // Remove the quotes from the value
      kv_stream.ignore();
      std::getline(kv_stream, value, '\"');

      map[key] = value;
    }

    return map;
  }

  std::string to_string(const std::list<Player *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::list<Town *> &list) const {
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

  std::string to_string(const std::list<Road *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::list<Land *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::list<Vertex *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::list<Progress *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::list<Knight *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::list<VictoryPoints *> &list) const {
    std::string result;
    for (const auto &obj : list) {
      result += obj->to_string() + "\n";
    }
    return result;
  }

  std::string to_string(const std::stack<Clay *> &stack) const {
    std::string result;
    std::stack<Clay *> tempStack = stack;
    while (!tempStack.empty()) {
      result += tempStack.top()->to_string();
      result += "\n";
      tempStack.pop();
    }
    return result;
  }

  std::string to_string(const std::stack<Mineral *> &stack) const {
    std::string result;
    std::stack<Mineral *> tempStack = stack;
    while (!tempStack.empty()) {
      result += tempStack.top()->to_string();
      result += "\n";
      tempStack.pop();
    }
    return result;
  }

  std::string to_string(const std::stack<Wheat *> &stack) const {
    std::string result;
    std::stack<Wheat *> tempStack = stack;
    while (!tempStack.empty()) {
      result += tempStack.top()->to_string();
      result += "\n";
      tempStack.pop();
    }
    return result;
  }

  std::string to_string(const std::stack<Wood *> &stack) const {
    std::string result;
    std::stack<Wood *> tempStack = stack;
    while (!tempStack.empty()) {
      result += tempStack.top()->to_string();
      result += "\n";
      tempStack.pop();
    }
    return result;
  }

  std::string to_string(const std::stack<Wool *> &stack) const {
    std::string result;
    std::stack<Wool *> tempStack = stack;
    while (!tempStack.empty()) {
      result += tempStack.top()->to_string();
      result += "\n";
      tempStack.pop();
    }
    return result;
  }

  std::string to_string(const std::vector<int> &vector) const {
    std::string result;
    for (const auto &number : vector) {
      result += std::to_string(number);
      result += " ";
    }
    return result;
  }
};
