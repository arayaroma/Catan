#include "Player.h"
using namespace std;

Player::Player(string namePlayer, int scorePlayer) {
	name = namePlayer;
	score = scorePlayer;
}
string Player::getName() { return name; }
void Player::setName(string namePlayer) { name = namePlayer; }
int Player::getScore() { return score; }
void Player::setScore(int scorePLayer) { score = scorePLayer; }