#pragma once
class Program(){
    private:
        int turn;
    public:
    void assemblyLand();
    void assignLand();
    void firstMove(std::string);
    void placeRoad();
    void placeTown();
    void play();
    void assignMaterial();
    void createCardStacks();
    void loadCards();
    void loadMaterialCards();
    void loadDevelopCards();
    void shuffleCard();
    int rollDice();
    void tradeMaterials();
    void build();
    void playDevelopCard();
}