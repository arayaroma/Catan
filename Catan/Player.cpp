#include "Player.hpp"

Player::Player() {
  this->name = "";
  this->color = "";
  this->score = NULL;
}

Player::Player(string name, int score) {
  this->name = name;
  this->score = score;
}

void Player::setName(string name) { this->name = name; }
string Player::getName() const { return name; }

void Player::setColor(string color) { this->color = color; }
string Player::getColor() const { return this->color; }

void Player::setScore(int score) { this->score = score; }
int Player::getScore() const { return this->score; }