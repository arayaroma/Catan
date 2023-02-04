#include "BuyView.hpp"

void BuyView::loadView() {
	view.create(sf::VideoMode(700, 680), "Buy");
	image.loadFromFile("Images/Desierto.png");
	sprite.setTexture(image);
	font.loadFromFile("mononoki.ttf");
	view.setFramerateLimit(120);
    
}

void BuyView::goView() {

    loadView();
    view.draw(sprite);
    while (view.isOpen()) {
        while (view.pollEvent(eventTest)) {
            switch (eventTest.type) {
                view.waitEvent(eventTest);
            case sf::Event::MouseButtonPressed:
                showCoordinates(eventTest);
                
                break;
            case sf::Event::Closed:
                view.close();
                break;
            }
            break;
        }
        view.clear();
        view.draw(sprite);
        createButtons();
        drawButton(p);
        drawButton(buy);
        drawView();
        view.display(); 
    }
}
void BuyView::loadProgressPaths() {



}
void BuyView::loadKnightPaths() {



}
void BuyView::loadVictoryPointsPaths() {


}

void BuyView::drawView() {

    printImages("Images/knightCards/mini_knightCard1.png",30,10);
    printImages("Images/knightCards/mini_knightCard2.png", 160, 10);
    printImages("Images/knightCards/mini_knightCard3.png", 290, 10);
    printImages("Images/knightCards/mini_knightCard4.png", 420, 10);
    printImages("Images/knightCards/mini_knightCard5.png", 550, 10);

    printImages("Images/victoryPointsCards/mini_victoryPointCard1.png", 30, 220);
    printImages("Images/victoryPointsCards/mini_victoryPointCard2.png", 160, 220);
    printImages("Images/victoryPointsCards/mini_victoryPointCard3.png", 290, 220);
    printImages("Images/victoryPointsCards/mini_victoryPointCard4.png", 420, 220);
    printImages("Images/victoryPointsCards/mini_victoryPointCard5.png", 550, 220);

    printImages("Images/progressCards/mini_progressCard1.png", 160, 430);
    printImages("Images/progressCards/mini_progressCard2.png", 290, 430);
    printImages("Images/progressCards/mini_progressCard3.png", 420, 430);

}
void BuyView::printImages(string imagePath, double posX, double posY) {
    sf::Texture path;
    path.loadFromFile(imagePath);
    sf::Sprite tempSprite(path);
    tempSprite.setPosition(static_cast<float>(posX), static_cast<float>(posY));
    view.draw(tempSprite);
}

void BuyView::createButtons() {
    p = Button("f", { 80, 0 }, 16, sf::Color::Green, sf::Color::Black);
    p.setFont(font);
    p.setPosition({ 10,10 }, 3);

    buy = Button("Comprar", { 100, 35 }, 16, sf::Color::Green, sf::Color::Black);
    buy.setFont(font);
    buy.setPosition({ 300,640 },3);

    buy = Button("caballero", { 650, 200 }, 16, sf::Color::Green, sf::Color::Black);
    buy.setFont(font);
    buy.setPosition({ 30,10 }, 3);
   
}

void BuyView::drawButton(Button& btn) {

    if (btn.isMouseOver(view)) {
        btn.setBackgroundColor(sf::Color::White);
    }
    else {
        btn.setBackgroundColor(sf::Color::Blue);
    }
    btn.drawButton(view);
    
}

void BuyView::showCoordinates(sf::Event event) {
    if (event.mouseButton.button == sf::Mouse::Left) {
        log("mouse x: " << event.mouseButton.x);
        log("mouse y: " << event.mouseButton.y);
    }
}