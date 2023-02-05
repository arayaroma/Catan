#include "BuyView.hpp"

void BuyView::loadView() {
	view.create(sf::VideoMode(700, 680), "Buy");
	image.loadFromFile("Images/Desierto.png");
	sprite.setTexture(image);
	font.loadFromFile("mononoki.ttf");
	view.setFramerateLimit(120);
    
}

void BuyView::goView() {

    game.makeDevelopCard();
    loadView();
    view.draw(sprite);
    while (view.isOpen()) {
        while (view.pollEvent(eventTest)) {
            switch (eventTest.type) {
                view.waitEvent(eventTest);
            case sf::Event::MouseButtonPressed:
                showCoordinates(eventTest);
                if (event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    VictoryButtonClicked(eventTest);
                    ProgressButtonClicked(eventTest);
                    KnightButtonClicked(eventTest);
                    BuyButtonPressed(eventTest);
                }
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
        drawButton(knight);
        drawButton(progress);
        drawButton(victory);
     
        drawView();
        view.display(); 
    }
}
void BuyView::loadProgressPaths() {
    progressIterator = game.progressCards->begin();
    if (progressIterator != game.progressCards->end()) {
        printImages((*progressIterator)->getImagePath(), 160, 430);
        progressIterator++;
        printImages((*progressIterator)->getImagePath(), 290, 430);
        progressIterator++;
        printImages((*progressIterator)->getImagePath(), 420, 430);
    }
}
void BuyView::loadKnightPaths() {
    knightIterator = game.knightCards->begin();
    if (knightIterator != game.knightCards->end()) {
        printImages((*knightIterator)->getImagePath(), 30, 10);
        knightIterator++;
        printImages((*knightIterator)->getImagePath(), 160, 10);
        knightIterator++;
        printImages((*knightIterator)->getImagePath(), 290, 10);
        knightIterator++;
        printImages((*knightIterator)->getImagePath(), 420, 10);
        knightIterator++;
        printImages((*knightIterator)->getImagePath(), 550, 10);
    }
}
void BuyView::loadVictoryPointsPaths() {
    victoryIterator = game.victoryPointCards->begin();
    if (victoryIterator != game.victoryPointCards->end()) {
        printImages((*victoryIterator)->getImagePath(), 30, 220);
        victoryIterator++;
        printImages((*victoryIterator)->getImagePath(), 160, 220);
        victoryIterator++;
        printImages((*victoryIterator)->getImagePath(), 290, 220);
        victoryIterator++;
        printImages((*victoryIterator)->getImagePath(), 420, 220);
        victoryIterator++;
        printImages((*victoryIterator)->getImagePath(), 550, 220);
    }
}
void BuyView::KnightButtonClicked(sf::Event event) {
    if (knight.isPressed(event)) {
        isKnightButtonClicked = true;  
    }
    else {
        isProgressButtonClicked = false;
        isVictoryButtonClicked = false;
    }
}
void BuyView::ProgressButtonClicked(sf::Event event) {
    if (knight.isPressed(event)) {
        isProgressButtonClicked = true;
    }
    else {
        isKnightButtonClicked = false;
        isVictoryButtonClicked = false;
    }
}
void BuyView::VictoryButtonClicked(sf::Event event) {
    if (victory.isPressed(event)) {
        isVictoryButtonClicked = true;
    }
    else {
        isProgressButtonClicked = false;
        isKnightButtonClicked = false;
    }
}
void BuyView::BuyButtonPressed(sf::Event event) {
    if (buy.isPressed(event)) {
        this->isBuyClicked = true;
    }
}
void BuyView::drawView() {
    loadVictoryPointsPaths();
    loadProgressPaths();
    loadKnightPaths();
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

    knight = Button("caballero", { 650, 200 }, 16, sf::Color::Green, sf::Color::Black);
    knight.setFont(font);
    knight.setPosition({ 30,10 }, 3);

    progress = Button("progreso", { 420, 200  }, 16, sf::Color::Green, sf::Color::Black);
    progress.setFont(font);
    progress.setPosition({ 150,400 }, 3);

    victory = Button("puntos de Victoria", { 650, 200 }, 16, sf::Color::Green, sf::Color::Black);
    victory.setFont(font);
    victory.setPosition({ 30,220  }, 3);
   
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