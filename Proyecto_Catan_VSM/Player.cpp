#include "Player.hpp"
using namespace std;

Player::Player(string name, int score) {
  this->name = name;
  this->score = score;
}

void Player::setName(string name) { this->name = name; }
string Player::getName() { return name; }

void Player::setScore(int score) { this->score = score; }
int Player::getScore() { return this->score; }