#include "Player.hpp"

Player::Player() {
  this->name = "";
  this->color = "";
  this->score = NULL;
  this->firstTurnFinished = false;
  towns = new list<Town*>();
  roads = new list<Road*>();
  citys = new list<City*>();
  //carts
  woolCard = new list<Wool*>();
  woodCard = new list<Wood*>();
  clayCard = new list<Clay*>();
  mineralCard = new list<Mineral*>();
  wheatlCard = new list<Wheat*>();
  progressCards = new list<Progress*>();
  knightCards = new list<Knight*>();
  victoryPointsCards = new list<VictoryPoints*>();
  this->progressDiscovery = 0;
  this->progressMonopoly = nullptr;
}

Player::Player(string name, int score, string color) {
  this->name = name;
  this->score = score;
  this->color = color;
  this->firstTurnFinished = false;
  towns = new list<Town*>();
  roads = new list<Road*>();
  citys = new list<City*>();
  //carts
  woolCard = new list<Wool*>();
  woodCard = new list<Wood*>();
  clayCard = new list<Clay*>();
  mineralCard = new list<Mineral*>();
  wheatlCard = new list<Wheat*>();
  progressCards = new list<Progress*>();
  knightCards = new list<Knight*>();
  victoryPointsCards = new list<VictoryPoints*>();
  this->progressDiscovery = 0;
  this->progressMonopoly = nullptr;
}

void Player::setName(string name) { this->name = name; }
string Player::getName() const { return name; }

void Player::setColor(string color) { this->color = color; }
string Player::getColor() const { return this->color; }

void Player::setScore(int score) { this->score += score; }
int Player::getScore() const { return this->score; }