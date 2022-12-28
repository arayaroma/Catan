#pragma once
class Player(){
    private:
    std::string name;
    int score;
    public:
    Player();
    Player(std::string namePlayer, std::string scorePlayer);
    std::string getName();
    void setName();
    std::string getScore();
    void setScore();
}