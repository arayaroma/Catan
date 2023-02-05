#include "TradeView.h"


void TradeView::loadView() {
    view.create(sf::VideoMode(540, 350), "Trade");
    image.loadFromFile("Images/Desierto.png");
    sprite.setTexture(image);
    font.loadFromFile("mononoki.ttf");
    view.setFramerateLimit(120);

}

void TradeView::goView() {
    game.makeMaterialCard(); 
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
        drawButton(wheat);
        drawButton(wool);
        drawButton(wood);
        drawButton(clay);
        drawButton(mineral);
        drawButton(trade);
        drawView();
        view.display();
    }
}


void TradeView::drawView() {
    printImages((game.wheatCards->top())->getImagePath(), 15, 10);
    printImages((game.woodCards->top())->getImagePath(), 125, 10);
    printImages((game.woolCards->top())->getImagePath(), 235, 10);
    printImages((game.clayCards->top())->getImagePath(), 345, 10);
    printImages((game.mineralCards->top())->getImagePath(), 455, 10);
}
void TradeView::printImages(string imagePath, double posX, double posY) {
    sf::Texture path;
    path.loadFromFile(imagePath);
    sf::Sprite tempSprite(path);
    tempSprite.setPosition(static_cast<float>(posX), static_cast<float>(posY));
    view.draw(tempSprite);
}

void TradeView::createButtons() {
    p = Button("f", { 80, 0 }, 16, sf::Color::Green, sf::Color::Black);
    p.setFont(font);
    p.setPosition({ 10,10 }, 3);

    trade = Button("Trueque", { 90, 35 }, 16, sf::Color::Green, sf::Color::Black);
    trade.setFont(font);
    trade.setPosition({ 225,250 }, 3);

    wheat = Button("Intercambiar", { 90, 25 }, 12, sf::Color::Green, sf::Color::Black);
    wheat.setFont(font);
    wheat.setPosition({ 10,130 }, 3);

    wood = Button("Intercambiar", { 90, 25 }, 12, sf::Color::Green, sf::Color::Black);
    wood.setFont(font);
    wood.setPosition({ 120,130 }, 3);

    wool = Button("Intercambiar", { 90, 25 }, 12, sf::Color::Green, sf::Color::Black);
    wool.setFont(font);
    wool.setPosition({ 230,130 }, 3);

    clay = Button("Intercambiar", { 90, 25 }, 12, sf::Color::Green, sf::Color::Black);
    clay.setFont(font);
    clay.setPosition({ 340,130 }, 3);

    mineral = Button("Intercambiar", { 90, 25 }, 12, sf::Color::Green, sf::Color::Black);
    mineral.setFont(font);
    mineral.setPosition({ 450,130 }, 3);

}

void TradeView::drawButton(Button& btn) {

    if (btn.isMouseOver(view)) {
        btn.setBackgroundColor(sf::Color::White);
    }
    else {
        btn.setBackgroundColor(sf::Color::Cyan);
    }
    btn.drawButton(view);

}

void TradeView::showCoordinates(sf::Event event) {
    if (event.mouseButton.button == sf::Mouse::Left) {
        log("mouse x: " << event.mouseButton.x);
        log("mouse y: " << event.mouseButton.y);
    }
}
