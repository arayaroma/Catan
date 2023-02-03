#include "PlayView.hpp"

PlayView::PlayView() {
  landsList = new list<Land *>();
  vertexesList = new list<Vertex *>();
}

PlayView::PlayView(list<Player *> *players) { game.players = players; }

/*methods of creating labels*/
void PlayView::createLabelNumTurn() {

  titleTurn = new Label("Turno:  ", sf::Color(0, 0, 255, 128), font,sf::Text::Bold, 20, 1000.f, 2.f);
  
  labelNumTurn = new Label(std::to_string(numTurn), sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 1100.f, 2.f);
  
  infoFisrtTurn = new Label("Primera Vuelta, por favor elija 2 poblados y pase de turno",sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 250.f, 525.f);

  labelNumDice = new Label(std::to_string(numDice), sf::Color(0, 0, 255, 128),font, sf::Text::Bold, 20, 1150.f, 570.f);


  titleTurn = new Label("Turno:  ", sf::Color(0, 0, 255, 128), font,
                        sf::Text::Bold, 20, 1080.f, 680.f);
  labelNumTurn = new Label(std::to_string(numTurn), sf::Color(0, 0, 255, 128),
                           font, sf::Text::Bold, 20, 1160.f, 680.f);
  infoFisrtTurn = new Label(
      "Primera Vuelta, por favor elija 2 poblados y pase de turno",
      sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 250.f, 525.f);
  labelNumDice = new Label(std::to_string(diceInstance.getActualNumber()),
                           sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20,
                           1150.f, 570.f);

}
void PlayView::createLabels() {
  materialCard = new Label("Cartas de Materiales", sf::Color(0, 0, 255, 128),
                           font, sf::Text::Bold, 20, 5.f, 230.f);
  developCard = new Label("Cartas de Desarrollo", sf::Color(0, 0, 255, 128),
                          font, sf::Text::Bold, 20, 5.f, 360.f);
  pricingTable = new Label("Tabla de precios", sf::Color(0, 0, 255, 128), font,
                           sf::Text::Bold, 20, 5.f, 0.f);
  turns = new Label("Jugadores", sf::Color(0, 0, 255, 128), font,
                    sf::Text::Bold, 20, 1070.f, 60.f);
  cards = new Label("Componentes", sf::Color(0, 0, 255, 128), font,
                    sf::Text::Bold, 20, 565.f, 575.f);
}
void PlayView::createLabelNamePlayers() {
    playerIterator = beginPlayerIterator();
    if (isPlayerListTraversal()) {
        if (isThreePlayers())
            createThreePlayersLabel();
         
    }
}
        void PlayView::loadthreeXone() {

            firsThreeXone = new Label("3:1", sf::Color::Black, font, sf::Text::Bold, 20, 500.f, 20.f);
            view.draw(firsThreeXone->getTextInstance());

            secondThreeXone = new Label("3:1", sf::Color::Black, font, sf::Text::Bold, 20, 838.f, 75.f);
            view.draw(secondThreeXone->getTextInstance());

            thirdThreeXone = new Label("3:1", sf::Color::Black, font, sf::Text::Bold, 20, 910.f, 238.f);
            view.draw(thirdThreeXone->getTextInstance());

            fourThreeXone = new Label("3:1", sf::Color::Black, font, sf::Text::Bold, 20, 510.f, 435.f);
            view.draw(fourThreeXone->getTextInstance());
        }

        void PlayView::createButtons() {

            p = Button("Turn", { 0, 0 }, 16, sf::Color::Green, sf::Color::Black);
            turn = Button("Turn", { 120, 35 }, 16, sf::Color::Green, sf::Color::Black);
            trade = Button("Trade", { 120, 35 }, 16, sf::Color::Green, sf::Color::Black);
            buy = Button("Buy", { 120, 35 }, 16, sf::Color::Green, sf::Color::Black);
            option1 = Button("Option1", { 120, 35 }, 16, sf::Color::Green, sf::Color::Black);
            save = Button("Guardar", { 120, 35 }, 16, sf::Color::Green, sf::Color::Black);
            close = Button("Close", { 120, 35 }, 16, sf::Color::Green, sf::Color::Black);

            setButtonOrigins();

        }
        void PlayView::setButtonOrigins() {

            p.setFont(font);
            p.setPosition({ 0, 0 }, 3);

            turn.setFont(font);
            turn.setPosition({ 985, 600 }, 3);

            trade.setFont(font);
            trade.setPosition({ 20, 600 }, 3);

            buy.setFont(font);
            buy.setPosition({ 150, 600 }, 3);

            option1.setFont(font);
            option1.setPosition({ 1120, 600 }, 3);

            save.setFont(font);
            save.setPosition({ 1120,660 }, 3);

            close.setFont(font);
            close.setPosition({ 985,660 }, 3);
        }

        void PlayView::drawButtons() {
            createButtons();
            loadRegisterButtons(p);
            loadRegisterButtons(turn);
            loadRegisterButtons(trade);
            loadRegisterButtons(buy);
            loadRegisterButtons(option1);
            loadRegisterButtons(save);
            loadRegisterButtons(close);
        }
    

        void PlayView::loadPlayersRectangle() {
            playerRectangle.setPosition(1020, 100);
            playerRectangle.setOutlineColor(sf::Color::White);
            playerRectangle.setSize({ 220, 400 });
            playerRectangle.setFillColor(sf::Color(255, 255, 255, 128));

            turnRectangleOne.setPosition(1020, 100);
            turnRectangleOne.setOutlineColor(sf::Color::White);
            turnRectangleOne.setSize({ 220, 100 });
            turnRectangleOne.setFillColor(sf::Color(255, 255, 255, 128));

            turnRectangleTwo.setPosition(1020, 200);
            turnRectangleTwo.setOutlineColor(sf::Color::White);
            turnRectangleTwo.setSize({ 220, 100 });
            turnRectangleTwo.setFillColor(sf::Color(255, 255, 255, 128));

            turnRectangleThree.setPosition(1020, 300);
            turnRectangleThree.setOutlineColor(sf::Color::White);
            turnRectangleThree.setSize({ 220, 100 });
            turnRectangleThree.setFillColor(sf::Color(255, 255, 255, 128));

            turnRectangleFour.setPosition(1020, 400);
            turnRectangleFour.setOutlineColor(sf::Color::White);
            turnRectangleFour.setSize({ 220, 100 });
            turnRectangleFour.setFillColor(sf::Color(255, 255, 255, 128));
            drawRectangleShapes(); 
        }

     void PlayView::drawRectangleShapes() {
        view.draw(playerRectangle);
        view.draw(turnRectangleOne);
        view.draw(turnRectangleTwo);
        view.draw(turnRectangleThree);
        view.draw(turnRectangleFour);

     }

void PlayView::loadRegisterButtons(Button& button) {
    if (button.isMouseOver(view)) {
        button.setBackgroundColor(sf::Color::White);
    }
    else {
        button.setBackgroundColor(sf::Color::Blue);

        if (isFourPlayers())
            createFourPlayersLabel();

    }
}
void PlayView::createLabelCardPlayer() {
    clayCard = new Label(std::to_string((*game.playerIterator)->clayCard->size()),
        sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20,
        375.f, 620.f);
    mineralPlayerCard = new Label(
        std::to_string((*game.playerIterator)->mineralCard->size()),
        sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 415.f, 620.f);
    wheatPlayerCard = new Label(
        std::to_string((*game.playerIterator)->wheatlCard->size()),
        sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 455.f, 620.f);
    woodPlayerCard = new Label(
        std::to_string((*game.playerIterator)->woodCard->size()),
        sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 495.f, 620.f);
    woolPlayerCard = new Label(
        std::to_string((*game.playerIterator)->woolCard->size()),
        sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 535.f, 620.f);
}
void PlayView::createThreePlayersLabel() {
    player1 = new Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 1100.f, 120.f);
    playerIterator++;
    player2 = new Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 1100.f, 180.f);
    playerIterator++;
    player3 = new Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 1100.f, 240.f);
}

void PlayView::createFourPlayersLabel() {
    player1 = new Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 1100.f, 120.f);
    playerIterator++;
    player2 = new Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 1100.f, 180.f);
    playerIterator++;
    player3 = new Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 1100.f, 240.f);
    playerIterator++;
    player4 = new Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 1100.f, 300.f);
}

void PlayView::createLabelFigurePlayer() {
    townPlayer = new Label(std::to_string((*game.playerIterator)->towns->size()),
        sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20,
        600.f, 620.f);
    cityPlayer = new Label(std::to_string((*game.playerIterator)->citys->size()),
        sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20,
        640.f, 620.f);
    roadPlayer = new Label(std::to_string((*game.playerIterator)->roads->size()),
        sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20,
        680.f, 620.f);
}

/*methods of creating Buttons*/
void PlayView::createBuyButton() {
  buy = Button("Comprar", {120, 35}, 16, sf::Color::Green, sf::Color::White);
  buy.setFont(font);
  buy.setPosition({150, 600}, 3);
  buy.drawButton(view);
  buy.buttonInOutColors(sf::Color(0, 0, 150, 255), sf::Color(0, 0, 200, 255),
                        view);
}


void PlayView::createTradeButton() {
  trade = Button("Trueque", {120, 35}, 16, sf::Color::Green, sf::Color::White);
  trade.setFont(font);
  trade.setPosition({20, 600}, 3);
  trade.drawButton(view);
  trade.buttonInOutColors(sf::Color(0, 0, 150, 255), sf::Color(0, 0, 220, 255),
                          view);
}

void PlayView::createTurnButton() {
  turn = Button("Siguiente\nTurno", {120, 50}, 16, sf::Color::Green,
                sf::Color::White);
  turn.setFont(font);
  turn.setPosition({985, 600}, 3);
  turn.drawButton(view);
  turn.buttonInOutColors(sf::Color(0, 0, 150, 255), sf::Color(0, 0, 220, 255),
                         view);
}

void PlayView::createPButton() {
  p = Button("P", {0, 0}, 16, sf::Color::Green, sf::Color::Black);
  p.setFont(font);
  p.setPosition({0, 0}, 3);
  p.drawButton(view);
  p.buttonInOutColors(sf::Color(0, 0, 255, 255), sf::Color(0, 0, 225, 255),
                      view);
}

void PlayView::createOptionOneButton() {
  option1 =
      Button("Option1", {120, 35}, 16, sf::Color::Green, sf::Color::Black);
}

void PlayView::createSaveButton() {
  save = Button("Guardar", {120, 35}, 16, sf::Color::Green, sf::Color::Black);
}

void PlayView::createCloseButton() {
  close = Button("Close", {120, 35}, 16, sf::Color::Green, sf::Color::Black);
}

void PlayView::createDiceButton() {
  dice = Button("Dado", {120, 50}, 15, sf::Color::Green, sf::Color::White);
  dice.setFont(font);
  dice.setPosition({1120, 600}, 3);
  dice.drawButton(view);
  dice.buttonInOutColors(sf::Color(0, 0, 150, 255), sf::Color(0, 0, 220, 255),
                         view);
}


void PlayView::loadGameButtons() {
  loadPlayersRectangle();
  loadCardsRectangle();

  createBuyButton();
  createTradeButton();
  createTurnButton();
  createPButton();
  createOptionOneButton();
  createSaveButton();
  createCloseButton();
  createDiceButton();
}
/*methods of draw labels*/
void PlayView::drawLabelNumTurn() {
  createLabelNumTurn();
  view.draw(titleTurn->getTextInstance());
  view.draw(labelNumTurn->getTextInstance());
  view.draw(labelNumDice->getTextInstance());
  if (isFirstTurn) {
    view.draw(infoFisrtTurn->getTextInstance());
  }
}

void PlayView::drawLabels() {
  createLabels();
  view.draw(materialCard->getTextInstance());
  view.draw(developCard->getTextInstance());
  view.draw(pricingTable->getTextInstance());
  view.draw(turns->getTextInstance());
  view.draw(cards->getTextInstance());
}
void PlayView::drawLabelNamePlayers() {
    createLabelNamePlayers();
    if (isThreePlayers()) {
        view.draw(player1->getTextInstance());
        view.draw(player2->getTextInstance());
        view.draw(player3->getTextInstance());
    }
    if (isFourPlayers()) {
        view.draw(player1->getTextInstance());
        view.draw(player2->getTextInstance());
        view.draw(player3->getTextInstance());
        view.draw(player4->getTextInstance());
    }
}

void PlayView::drawLabelCardPlayer() {
    createLabelCardPlayer();
    view.draw(clayCard->getTextInstance());
    view.draw(mineralPlayerCard->getTextInstance());
    view.draw(wheatPlayerCard->getTextInstance());
    view.draw(woodPlayerCard->getTextInstance());
    view.draw(woolPlayerCard->getTextInstance());
}

void PlayView::drawLabelFigurePlayer() {
    createLabelFigurePlayer();
    view.draw(townPlayer->getTextInstance());
    view.draw(cityPlayer->getTextInstance());
    view.draw(roadPlayer->getTextInstance());
}

/*methods of print Card*/
void PlayView::printPlayerCard() {
  printImages("Images/playerCard/clayCard.png", 360, 640);
  printImages("Images/playerCard/mineralCard.png", 400, 640);
  printImages("Images/playerCard/wheatCard.png", 440, 640);
  printImages("Images/playerCard/woodCard.png", 480, 640);
  printImages("Images/playerCard/woolCard.png", 520, 640);
}
void PlayView::printPlayerFigure() {
    cityIterator = (*game.playerIterator)->citys->begin();
    townIterator = (*game.playerIterator)->towns->begin();
    if (townIterator != (*game.playerIterator)->towns->end())
        printImages((*townIterator)->getImagePath(), 590, 650);

    if (cityIterator != (*game.playerIterator)->citys->end())
        printImages((*cityIterator)->getImagePath(), 630, 650);
}

void PlayView::printMaterialCard() {
    printImages("Images/resourcesCards/clayCard.png", 0, 255);
    printImages("Images/resourcesCards/mineralCard.png", 70, 255);
    printImages("Images/resourcesCards/wheatCard.png", 140, 255);
    printImages("Images/resourcesCards/woodCard.png", 210, 255);
    printImages("Images/resourcesCards/woolCard.png", 280, 255);
    printImages("Images/extraCards/progressCardBackwards.png", 0, 385);
    printImages("Images/extraCards/pricingTable.jpeg", 0, 25);
    drawLabels();
}
/* methods for first turn*/
void PlayView::traverseLands(double x, double y) {
    it = landsList->begin();
    while (it != landsList->end()) {
        searhTown(x, y, it);
        it++;
    }
}

void PlayView::printTownPlayer(list<Vertex*>::iterator vIterator, int x,
    int y) {
    if ((*game.playerIterator)->towns->size() > 0) {
        if ((*game.playerIterator)->getTownFirstTurn() < 2) {
            initializeIteratorTownList();
            setIsClickedToVertexGraph(vIterator);
            if (townIterator != (*game.playerIterator)->towns->end())
                printImages((*townIterator)->getImagePath(),
                    (*vIterator)->getTown()->getPosX(),
                    (*vIterator)->getTown()->getPosY());
            setOwnerToVertexGraph(game.graph.getVertex((*vIterator)->getVertexId()));
            deleteTowntoPlayer();
            (*game.playerIterator)->setTownFirstTurn(1);
            if ((*game.playerIterator)->getTownFirstTurn() == 2) {
                receiveFirstMaterialCard();
            }
            view.display();
        }
    }
    (*game.playerIterator)->setFirstTurnFinished(true);
}

void PlayView::searhTown(double x, double y, list<Land*>::iterator it) {
    list<Vertex*>::iterator vIterator;
    vIterator = (*it)->getTownsList()->begin();
    while (vIterator != (*it)->getTownsList()->end()) {
        if (isTownClicked(vIterator, x, y)) {
            printTownPlayer(vIterator, (int)x, (int)y);
        }
        vIterator++;
    }
}

void PlayView::receiveFirstMaterialCard() {
    list<Land*>::iterator it;
    it = landsList->begin();
    while (it != landsList->end()) {
        receiveFirstCard(it);
        it++;
    }
}
void PlayView::receiveFirstCard(list<Land*>::iterator it) {
    list<Vertex*>::iterator vIterator;
    vIterator = (*it)->getTownsList()->begin();
    while (isVertexesListTraversalInTurn(vIterator, it)) {
        if (existsAnOwnerInVertex(vIterator)) {
            if (isActualPlayerName(vIterator))
                giveCardsToPlayerFirstTurn(it);
        }
        vIterator++;
    }
}
/*others methods*/

list<Player*>::iterator PlayView::beginPlayerIterator() const {
    return game.players->begin();
}

bool PlayView::isPlayerListTraversal() const {
    return (playerIterator != game.players->end());
}

bool PlayView::isThreePlayers() const { return (game.players->size() == 3); }
bool PlayView::isFourPlayers() const { return (game.players->size() == 4); }


void PlayView::loadCardsRectangle() {
  cardsRectangle = playerRectangle;
  cardsRectangle.setPosition(350, 600);
  cardsRectangle.setSize({600, 100});
  view.draw(cardsRectangle);
}




void PlayView::loadOcean() {
    
    OceanImg.loadFromFile("Images/Muelle/Ocean.png");
    OCeanSprite.setTexture(OceanImg);
    OCeanSprite.setPosition({ 400,0 });
    view.draw(OCeanSprite);

}


void PlayView::drawView() {
  view.clear();
  view.draw(sprite);
  loadGameButtons();
  drawLabels();
  loadOcean(); 
  loadthreeXone();
  printBoard();
  printTownsTest();
  printMaterialCard();
  drawLabelNamePlayers();
  drawLabelNumTurn();
  printPlayerCard();
  drawLabelCardPlayer();
  drawLabelFigurePlayer();
  printPlayerFigure();
  createButtons();
  
  view.display();
}



void PlayView::initializeIteratorTownList() {
  townIterator = (*game.playerIterator)->towns->begin();
}

void PlayView::setIsClickedToVertexGraph(list<Vertex *>::iterator it) {
  game.graph.getVertex((*it)->getVertexId())->setClicked(true);
}

bool PlayView::isPlayerTownListEmpty() const {
  return ((*game.playerIterator)->towns->size() == 0);
}

bool PlayView::playerIsPuttingTowns() const {
  return ((*game.playerIterator)->getTownFirstTurn() < 2);
}

bool PlayView::playerHasPutTwoTowns() const {
  return ((*game.playerIterator)->getTownFirstTurn() == 2);
}

bool PlayView::isPlayerTownsListTraversal() const {
  return (townIterator != (*game.playerIterator)->towns->end());
}

void PlayView::giveCardsToPlayerFirstTurn(list<Land *>::iterator landIterator) {
  if ((*landIterator)->getTypeLand() == "Mountain")
    (*game.playerIterator)->mineralCard->push_back(new Mineral());
  if ((*landIterator)->getTypeLand() == "Brick")
    (*game.playerIterator)->clayCard->push_back(new Clay());
  if ((*landIterator)->getTypeLand() == "Forest")
    (*game.playerIterator)->woodCard->push_back(new Wood());
  if ((*landIterator)->getTypeLand() == "Grass")
    (*game.playerIterator)->woolCard->push_back(new Wool());
  if ((*landIterator)->getTypeLand() == "Field")
    (*game.playerIterator)->wheatlCard->push_back(new Wheat());
}

void PlayView::firstTurn() {
  playerIterator = beginPlayerIterator();
  while (isPlayerListTraversal()) {
    if ((*playerIterator)->getFirstTurnFinished())
      isFirstTurn = false;
    else
      isFirstTurn = true;

    playerIterator++;
  }
}

void PlayView::deleteTowntoPlayer() {
  if (townIterator != (*game.playerIterator)->towns->end())
    (*game.playerIterator)->towns->pop_back(); // poner alerta aca
}

void PlayView::setOwnerToVertexGraph(Vertex *vertex) {
  game.graph.getVertex(vertex->getVertexId())->setOwner((*game.playerIterator));
}

bool PlayView::isTownClicked(list<Vertex *>::iterator vertexIterator, double x,
                             double y) {
  return (x > (*vertexIterator)->getTown()->getPosX() &&
          x < (*vertexIterator)->getTown()->getPosX() + 30 &&
          y > (*vertexIterator)->getTown()->getPosY() &&
          y < (*vertexIterator)->getTown()->getPosY() + 30);
}

void PlayView::loadView() {
  view.create(sf::VideoMode(1280, 720), "Play");
  image.loadFromFile("Images/catan_1280x720.jpg");
  sprite.setTexture(image);
  font.loadFromFile("mononoki.ttf");
  view.setFramerateLimit(120);
  game.playerIterator = beginPlayerIterator();
  game.loadLands();
  game.assignTownsToLand();
  game.makeGraph();
  landsList = game.getLandsList();
  start = true;
  srand((unsigned)time(nullptr));
}

void PlayView::goView() {
  loadView();
  drawView();
  view.draw(sprite);
  while (view.isOpen()) {
    while (view.pollEvent(eventTest)) {
      showCoordinates(eventTest);
      switch (eventTest.type) {
        //view.waitEvent(eventTest);
        case sf::Event::MouseButtonPressed:
          if (eventTest.MouseButtonPressed && isMouseLeftClicked(eventTest)) {
              if (isFirstTurn) {
                  traverseLands(getMousePositionX(view), getMousePositionY(view));
              }
              else {
                  isDiceButtonClicked(getMousePositionX(view), getMousePositionY(view));
              }
              isTurnButtonClicked(sf::Mouse::getPosition(view).x,
                  sf::Mouse::getPosition(view).y);
              
          }
          break;
          case sf::Event::Closed:
            view.close();
            break;
      }
      break;
    }
    drawView();
  }
}

void PlayView::isDiceButtonClicked(int x, int y) {
  if (dice.isMouseOver(view)) {
    if (!isDiceSpinned) {
      receiveMaterialCard(diceInstance.rollDice());
      isDiceSpinned = true;
    }
  }
}

bool PlayView::existsAnOwnerInVertex(list<Vertex *>::iterator vertexIterator) {
  return (game.graph.getVertex((*vertexIterator)->getVertexId())->getOwner() !=
          nullptr);
}

bool PlayView::isVertexesListTraversalInTurn(
    list<Vertex *>::iterator vertexIterator,
    list<Land *>::iterator landIterator) {
  return (vertexIterator != (*landIterator)->getTownsList()->end());
}

bool PlayView::isActualPlayerName(list<Vertex *>::iterator vertexIterator) {
  return (game.graph.getVertex((*vertexIterator)->getVertexId())
              ->getOwner()
              ->getName() == (*playerIterator)->getName());
}

void PlayView::giveCardsToPlayer(list<Land *>::iterator landIterator) {
  if ((*landIterator)->getTypeLand() == "Mountain")
    (*playerIterator)->mineralCard->push_back(new Mineral());

  if ((*landIterator)->getTypeLand() == "Brick")
    (*playerIterator)->clayCard->push_back(new Clay());

  if ((*landIterator)->getTypeLand() == "Forest")
    (*playerIterator)->woodCard->push_back(new Wood());

  if ((*landIterator)->getTypeLand() == "Grass")
    (*playerIterator)->woolCard->push_back(new Wool());

  if ((*landIterator)->getTypeLand() == "Field")
    (*playerIterator)->wheatlCard->push_back(new Wheat());
}

void PlayView::receiveCard(list<Land *>::iterator it) {
  list<Vertex *>::iterator vIterator;
  vIterator = (*it)->getTownsList()->begin();
  playerIterator = beginPlayerIterator();
  while (isPlayerListTraversal()) {
    while (isVertexesListTraversalInTurn(vIterator, it)) {
      if (existsAnOwnerInVertex(vIterator)) {
        if (isActualPlayerName(vIterator))
          giveCardsToPlayer(it);
      }
      vIterator++;
    }
    vIterator = (*it)->getTownsList()->begin();
    playerIterator++;
  }
}

void PlayView::receiveMaterialCard(int idLand) {
  list<Land *>::iterator it;
  it = landsList->begin();
  while (it != landsList->end()) {
    if ((*it)->getLandId() == idLand) {
      receiveCard(it);
      break;
    }
    it++;
  }
}

void PlayView::isTurnButtonClicked(int x, int y) {
  if (turn.isMouseOver(view)) {
    
    if (game.playerIterator != game.players->end()) {
      game.playerIterator++; 
      numTurn++;
     
      isDiceSpinned = false;
    }
    if (game.playerIterator == game.players->end()) {
      game.playerIterator = beginPlayerIterator();
      firstTurn();
      numTurn = 1;
      
      isDiceSpinned = false;
    }
  }
}

void PlayView::setTurn(int numberPlayers) {
  
  log(turnNumber);
  int i = 0;
  if (turnNumber == numberPlayers) {
    turnNumber = 0;
    i = 100;
    
  } else {
   
    i = i + 45;
    turnNumber++;
  }
}

void PlayView::drawTurn(int turns, int posiI) {


}

void PlayView::printImages(string imagePath, double posX, double posY) {
  sf::Texture path;
  path.loadFromFile(imagePath);
  sf::Sprite tempSprite(path);
  tempSprite.setPosition(static_cast<float>(posX), static_cast<float>(posY));
  view.draw(tempSprite);
}

void PlayView::initializeLandsList() {
  isPrintedFalse();
  it = landsList->begin();
}

void PlayView::isPrintedFalse() {
  Vertex *auxVertex = game.graph.firstVertex;
  while (auxVertex != nullptr) {
    auxVertex->setPrinted(false);
    auxVertex = auxVertex->next;
  }
}

void PlayView::printBoard() {
  double top_height = 50, bot_height = 50, cycle_cord_x = 0, i = 1;
  initializeLandsList();
  bot_height += 280;
  it2 = landsList->begin();
  std::advance(it2, 16);
  for (cycle_cord_x = 530; cycle_cord_x <= 700; cycle_cord_x += 85) {
    traverseFirstAndLastRow(cycle_cord_x, top_height, bot_height);
  }
  lastIteration = false;
  top_height += 70;
  bot_height = 250;
  lastIterationNumber = 755;
  it2 = landsList->begin();
  std::advance(it2, 12);
  for (cycle_cord_x = 487.5; cycle_cord_x <= 757.5; cycle_cord_x += 85) {
    traverseSecondAndNextToLastRow(cycle_cord_x, top_height, bot_height);
  }
  lastIteration = false;
  top_height += 70;
  lastIterationNumber = 760;
  it2 = landsList->begin();
  std::advance(it2, 7);
  for (cycle_cord_x = 445; cycle_cord_x <= 785; cycle_cord_x += 85) {
    traverseMiddleRow(cycle_cord_x, top_height, bot_height);
  }
}

void PlayView::printTownsTest() {
  double top_height = 40, bot_height = 40, cycle_cord_x = 0, i = 1;
  initializeLandsList();
  bot_height += 280;
  it2 = landsList->begin();
  std::advance(it2, 16);
  for (cycle_cord_x = 530; cycle_cord_x <= 700; cycle_cord_x += 85) {
    traverseFirstAndLastRowTest(cycle_cord_x, top_height, bot_height);
  }
  lastIteration = false;
  top_height += 70;
  bot_height = 250;
  lastIterationNumber = 755;
  it2 = landsList->begin();
  std::advance(it2, 12);
  for (cycle_cord_x = 487.5; cycle_cord_x <= 757.5; cycle_cord_x += 85) {
    traverseSecondAndNextToLastRowTest(cycle_cord_x, top_height, bot_height);
  }
  lastIteration = false;
  top_height += 70;
  lastIterationNumber = 760;
  it2 = landsList->begin();
  std::advance(it2, 7);
  for (cycle_cord_x = 445; cycle_cord_x <= 785; cycle_cord_x += 85) {
    traverseMiddleRowTest(cycle_cord_x, top_height, bot_height);
  }
}

void PlayView::setTempImagePath(string image) { this->tempImagePath = image; }
bool PlayView::isLandsListTraversal() const { return (it != landsList->end()); }
void PlayView::iterateLand() { it++; }
void PlayView::iterateLand2() { it2++; }

bool PlayView::isLastIteration(double number) const {
  return (number == lastIterationNumber);
}

void PlayView::lastIterationBehaviour(double number) {
  if (isLastIteration(number))
    lastIteration = true;
  else
    lastIteration = false;
}

void PlayView::setPosXYtoLand(double posX, double posY,
                              list<Land *>::iterator auxIt) {
  (*auxIt)->setPosX(posX);
  (*auxIt)->setPosY(posY);
}

void PlayView::setAndTraverse(double posX, double posY,
                              list<Land *>::iterator auxIt) {
  setTempImagePath((*auxIt)->getImagePath());
  setPosXYtoLand(posX, posY, auxIt);
  printImages(tempImagePath, posX, posY);
}

void PlayView::setAndTraverseTest(double posX, double posY,
                                  list<Land *>::iterator auxIt) {
  C_Traversal(posX, posY, auxIt);
}

void PlayView::initializeVertexesList(list<Land *>::iterator auxIt) {
  vertexesList = (*auxIt)->getTownsList();
  vertexIterator = vertexesList->begin();
}

bool PlayView::isVertexesListTraversal() const {
  return (vertexIterator != vertexesList->end());
}

void PlayView::iterateVertex() { vertexIterator++; }

bool PlayView::isTwoLastVertex() const {
  return (vertexIterationNumber == 3 || vertexIterationNumber == 5);
}

void PlayView::traverseFirstAndLastRow(double posX, double topHeight,
                                       double botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(posX, topHeight, it);
    iterateLand();

    setAndTraverse(posX, botHeight, it2);
    iterateLand2();
  }
}

void PlayView::traverseSecondAndNextToLastRow(double posX, double topHeight,
                                              double botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(posX, topHeight, it);
    iterateLand();

    setAndTraverse(posX, botHeight, it2);
    iterateLand2();
  }
}

void PlayView::traverseMiddleRow(double posX, double topHeight,
                                 double botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(posX, topHeight, it2);
    iterateLand2();
  }
}

void PlayView::traverseFirstAndLastRowTest(double posX, double topHeight,
                                           double botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverseTest(posX, topHeight, it);
    iterateLand();

    setAndTraverseTest(posX, botHeight, it2);
    iterateLand2();
  }
}

void PlayView::traverseSecondAndNextToLastRowTest(double posX, double topHeight,
                                                  double botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverseTest(posX, topHeight, it);
    iterateLand();

    setAndTraverseTest(posX, botHeight, it2);
    iterateLand2();
  }
}

void PlayView::traverseMiddleRowTest(double posX, double topHeight,
                                     double botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverseTest(posX, topHeight, it2);
    iterateLand2();
  }
}

void PlayView::C_Traversal(double posX, double posY,
                           list<Land *>::iterator auxIt) {
  vertexIterationNumber = 1;
  initializeVertexesList(auxIt);

  for (vertexIterationNumber; vertexIterationNumber < 7;
       vertexIterationNumber++) {
    if (isVertexesListTraversal()) {
      loadHexagonNodes(vertexIterator, posX, posY, vertexIterationNumber);
      iterateVertex();
    }
  }
}

double PlayView::getFormula(int vertexId) const {
  if (vertexId == 1)
    return firstAngle;
  if (vertexId == 2)
    return secondAngle;
  if (vertexId == 3)
    return thirdAngle;
  if (vertexId == 4)
    return fourthAngle;
  if (vertexId == 5)
    return fifthAngle;
  if (vertexId == 6)
    return sexthAngle;
  return 0;
}

void PlayView::printTowns(double x, double y) {
  string tempImagePath = "Images/Town.png";
  printImages(tempImagePath, static_cast<int>(x), static_cast<int>(y));
}

void PlayView::setPosXYtoVertex(list<Vertex *>::iterator vertexIterator,
                                double x, double y) {
  (*vertexIterator)->town->setPosX(x);
  (*vertexIterator)->town->setPosY(y);
}

void PlayView::loadHexagonNodes(list<Vertex *>::iterator itX, double posX,
                                double posY, int iterationNumber) {
  double relativePositionX =
      posX + landsRadius + (landsRadius * cos(getFormula(iterationNumber)));
  double relativePositionY =
      posY + landsRadius + (landsRadius * sin(getFormula(iterationNumber)));

  if (!getIsVertexGraphClicked(itX)) {
    if (!getIsVertexGraphPrinted(itX)) {
      game.graph.getVertex((*itX)->getVertexId())->setPrinted(true);
      printTowns(relativePositionX, relativePositionY);
      setPosXYtoVertex(itX, relativePositionX, relativePositionY);
      setPosXYtoVertexesGraph((*itX)->getVertexId(), relativePositionX,
                              relativePositionY);
    }
  } else if (!getIsVertexGraphPrinted(itX)) {
    game.graph.getVertex((*itX)->getVertexId())->setPrinted(true);
    townIterator =
        game.graph.getVertex((*itX)->getVertexId())
            ->getOwner()
            ->towns->begin(); //(*game.playerIterator)->towns->begin();
    if (townIterator !=
        game.graph.getVertex((*itX)->getVertexId())->getOwner()->towns->end())
      printImages((*townIterator)->getImagePath(), relativePositionX,
                  relativePositionY);
  }
}

bool PlayView::getIsVertexGraphClicked(list<Vertex *>::iterator it) {
  if (!game.graph.getVertex((*it)->getVertexId())->isClicked())
    return false;
  return true;
}

bool PlayView::getIsVertexGraphPrinted(list<Vertex *>::iterator it) {
  if (!game.graph.getVertex((*it)->getVertexId())->isPrinted())
    return false;
  return true;
}

void PlayView::setPosXYtoVertexesGraph(int vertexId, double posX, double posY) {
  game.graph.getVertex(vertexId)->getTown()->setPosX(posX);
  game.graph.getVertex(vertexId)->getTown()->setPosY(posY);
}

void PlayView::consolePrintLandAndVertex() {
  game.printLand(landsList);
  it = landsList->begin();
  while (it != landsList->end()) {
    log("landId: " << (*it)->getLandId());
    game.printVertex((*it)->getTownsList());
    it++;
  }
}

void PlayView::showCoordinates(sf::Event event) {
  if (event.mouseButton.button == sf::Mouse::Left) {
    log("mouse x: " << event.mouseButton.x);
    log("mouse y: " << event.mouseButton.y);
  }
}