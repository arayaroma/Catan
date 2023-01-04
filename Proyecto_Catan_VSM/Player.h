#pragma once
#include <iostream>
class Player {
private:
	std::string name;
	int score;

public:
	Player() {};
	Player(std::string namePlayer, int scorePlayer);
	std::string getName();
	void setName(std::string namePlayer);
	int getScore();
	void setScore(int scorePLayer);
};

