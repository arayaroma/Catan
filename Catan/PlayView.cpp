#include "PlayView.hpp"

PlayView::PlayView() {
  landsList = new list<Land *>();
  vertexesList = new list<Vertex *>();
  ownerBiggestArmy = "name";
}

PlayView::PlayView(list<Player *> *players, string fileName) {
  game.players = players;
  actualMatchName = fileName;
  ownerBiggestArmy = "name";
}

PlayView::PlayView(Game &obj) { game = Game(obj); }

/*methods of creating labels*/
void PlayView::createLabelNumTurn() {

  titleTurn = Label("Turno:  ", sf::Color(0, 0, 255, 128), font, sf::Text::Bold,
                    20, 1050.f, 370.f);
  labelNumTurn = Label((*game.playerIterator)->getName(), sf::Color(0, 0, 0),
                       font, sf::Text::Bold, 20, 1145.f, 370.f);

  infoFisrtTurn =
      Label("Primera Ronda, por favor elija 2 poblados y pase de turno",
            sf::Color(0, 0, 0), font, sf::Text::Bold, 20, 250.f, 510.f);
  labelNumDice =
      Label(std::to_string(diceInstance.getActualNumber()), sf::Color(0, 0, 0),
            font, sf::Text::Bold, 20, 1150.f, 570.f);

  labelBuy = Label("Comprar", sf::Color(0, 0, 255), font, sf::Text::Bold, 20,
                   200.f, 585.f);

  numDevelopCard =
      Label(std::to_string(game.getKnightCards()->size() +
                           game.getProgressCards()->size() +
                           game.getVictoryPointsCards()->size()),
            sf::Color(0, 0, 0), font, sf::Text::Bold, 20, 80.f, 450.f);

  owner = Label("Propietario: ", sf::Color(0, 0, 255), font, sf::Text::Bold, 20,
                200.f, 0.f);

  ownerName = Label(ownerBiggestArmy, sf::Color(0, 0, 255), font,
                    sf::Text::Bold, 20, 360.f, 0.f);
}

void PlayView::createLabelCardPlayer() {
  clayCard =
      Label(std::to_string((*game.playerIterator)->clayCard->size()),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 375.f, 620.f);
  mineralPlayerCard =
      Label(std::to_string((*game.playerIterator)->mineralCard->size()),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 415.f, 620.f);
  wheatPlayerCard =
      Label(std::to_string((*game.playerIterator)->wheatlCard->size()),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 455.f, 620.f);
  woodPlayerCard =
      Label(std::to_string((*game.playerIterator)->woodCard->size()),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 495.f, 620.f);
  woolPlayerCard =
      Label(std::to_string((*game.playerIterator)->woolCard->size()),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 535.f, 620.f);
}

void PlayView::createThreePlayersLabel() {
  player1 = Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128), font,
                  sf::Text::Bold, 20, 1100.f, 120.f);
  playerIterator++;
  player2 = Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128), font,
                  sf::Text::Bold, 20, 1100.f, 180.f);
  playerIterator++;
  player3 = Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128), font,
                  sf::Text::Bold, 20, 1100.f, 240.f);
}

void PlayView::createFourPlayersLabel() {
  player1 = Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128), font,
                  sf::Text::Bold, 20, 1100.f, 120.f);
  playerIterator++;
  player2 = Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128), font,
                  sf::Text::Bold, 20, 1100.f, 180.f);
  playerIterator++;
  player3 = Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128), font,
                  sf::Text::Bold, 20, 1100.f, 240.f);
  playerIterator++;
  player4 = Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128), font,
                  sf::Text::Bold, 20, 1100.f, 300.f);
}

void PlayView::createLabelFigurePlayer() {
  townPlayer =
      Label(std::to_string((*game.playerIterator)->towns->size() - 1),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 600.f, 620.f);
  cityPlayer =
      Label(std::to_string((*game.playerIterator)->citys->size() - 1),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 640.f, 620.f);
  roadPlayer =
      Label(std::to_string((*game.playerIterator)->roads->size() - 1),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 680.f, 620.f);
}

void PlayView::createLabelMaterialCardGame() {
  clayGame = Label(std::to_string(game.clayCards->size()), sf::Color(0, 0, 0),
                   font, sf::Text::Bold, 20, 15.f, 240.f);
  mineralGame =
      Label(std::to_string(game.mineralCards->size()), sf::Color(0, 0, 0), font,
            sf::Text::Bold, 20, 70.f, 240.f);
  wheatGame = Label(std::to_string(game.wheatCards->size()), sf::Color(0, 0, 0),
                    font, sf::Text::Bold, 20, 120.f, 240.f);
  woodGame = Label(std::to_string(game.woodCards->size()), sf::Color(0, 0, 0),
                   font, sf::Text::Bold, 20, 170.f, 240.f);
  woolGame = Label(std::to_string(game.woolCards->size()), sf::Color(0, 0, 0),
                   font, sf::Text::Bold, 20, 225.f, 240.f);
}

void PlayView::createLabels() {
  materialCard = Label("Materiales", sf::Color(0, 0, 255, 128), font,
                       sf::Text::Bold, 20, 25.f, 220.f);
  developCard = Label("Cartas de Desarrollo", sf::Color(0, 0, 255, 128), font,
                      sf::Text::Bold, 20, 5.f, 380.f);
  pricingTable = Label("Precios", sf::Color(0, 0, 255, 128), font,
                       sf::Text::Bold, 20, 25.f, 0.f);
  turns = Label("Jugadores", sf::Color(0, 0, 255, 128), font, sf::Text::Bold,
                20, 1070.f, 60.f);
  cards = Label("Componentes", sf::Color(0, 0, 255, 128), font, sf::Text::Bold,
                20, 565.f, 575.f);
  town =
      Label(std::to_string(game.getTownsList()->size()),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 150.f, 440.f);
  city =
      Label(std::to_string(game.getCitiesList()->size()),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 200.f, 440.f);
  road =
      Label(std::to_string(game.getRoadsList()->size()),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 250.f, 440.f);
}

void PlayView::printFiguresGame() {
  roadIterator = (*game.playerIterator)->roads->begin();
  cityIterator = (*game.playerIterator)->citys->begin();
  townIterator = (*game.playerIterator)->towns->begin();
  if (townIterator != (*game.playerIterator)->towns->end())
    printImages((*townIterator)->getImagePath(), 140, 480);

  if (cityIterator != (*game.playerIterator)->citys->end())
    printImages((*cityIterator)->getImagePath(), 190, 480);

  if (roadIterator != (*game.playerIterator)->roads->end())
    printImages((*roadIterator)->getImagePath(), 240, 480);
}

void PlayView::createLabelPlayerDevelopCard() {
  victory =
      Label(std::to_string((*game.playerIterator)->victoryPointsCards->size()),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 915.f, 620.f);

  knight =
      Label(std::to_string((*game.playerIterator)->knightCards->size()),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 875.f, 620.f);

  progress =
      Label(std::to_string((*game.playerIterator)->progressCards->size()),
            sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 790.f, 595.f);
}

void PlayView::createLabelScorePlayer() {
  titleScorePlayer = Label("Puntaje:", sf::Color(0, 0, 255, 128), font,
                           sf::Text::Bold, 20, 1050.f, 340.f);
  scorePlayer =
      Label(std::to_string((*game.playerIterator)->getScore()),
            sf::Color(0, 0, 0), font, sf::Text::Bold, 20, 1155.f, 340.f);
}

void PlayView::drawLabelMaterialGame() {
  createLabelMaterialCardGame();
  view.draw(wheatGame.getTextInstance());
  view.draw(mineralGame.getTextInstance());
  view.draw(clayGame.getTextInstance());
  view.draw(woolGame.getTextInstance());
  view.draw(woodGame.getTextInstance());
  view.draw(labelBuy.getTextInstance());
  view.draw(owner.getTextInstance());
}

void PlayView::printPlayerDevelopCard() {
  printImages("Images/playerCard/mini_progressCard1.png", 735, 640);
  printImages("Images/playerCard/mini_progressCard2.png", 775, 640);
  printImages("Images/playerCard/mini_progressCard3 .png", 815, 640);
  printImages("Images/playerCard/mini_knightCard1.png", 860, 640);
  printImages("Images/playerCard/mini_victoryPointCard1.png", 900, 640);
}

void PlayView::printMaterialCard() {
  printImages("Images/resourcesCards/clayCard.png", 0, 270);
  printImages("Images/resourcesCards/mineralCard.png", 50, 270);
  printImages("Images/resourcesCards/wheatCard.png", 100, 270);
  printImages("Images/resourcesCards/woodCard.png", 150, 270);
  printImages("Images/resourcesCards/woolCard.png", 200, 270);
  printImages("Images/extraCards/progressCardBackwards.png", 0, 410);
  printImages("Images/extraCards/pricingTable.jpeg", 0, 25);
  drawLabels();
}

void PlayView::createLabelNamePlayers() {
  playerIterator = beginPlayerIterator();
  if (isPlayerListTraversal()) {
    if (isThreePlayers())
      createThreePlayersLabel();
    if (isFourPlayers())
      createFourPlayersLabel();
  }
}

void PlayView::loadthreeXone() {

  firsThreeXone =
      Label("3:1", sf::Color::Black, font, sf::Text::Bold, 20, 500.f, 20.f);
  view.draw(firsThreeXone.getTextInstance());

  secondThreeXone =
      Label("3:1", sf::Color::Black, font, sf::Text::Bold, 20, 838.f, 75.f);
  view.draw(secondThreeXone.getTextInstance());

  thirdThreeXone =
      Label("3:1", sf::Color::Black, font, sf::Text::Bold, 20, 910.f, 238.f);
  view.draw(thirdThreeXone.getTextInstance());

  fourThreeXone =
      Label("3:1", sf::Color::Black, font, sf::Text::Bold, 20, 510.f, 435.f);

  view.draw(fourThreeXone.getTextInstance());
}

void PlayView::createButtons() {

  p = Button(".", {0, 0}, 16, sf::Color::Green, sf::Color::White);
  option1 =
      Button("Option1", {120, 35}, 16, sf::Color::Green, sf::Color::White);
  save = Button("Guardar", {120, 35}, 16, sf::Color::Green, sf::Color::White);
  close = Button("Close", {120, 35}, 16, sf::Color::Green, sf::Color::White);
  turn = Button("Siguiente\nTurno", {120, 50}, 16, sf::Color::Green,
                sf::Color::White);
  trade = Button("Trade", {120, 35}, 16, sf::Color::Green, sf::Color::White);
  // buy = Button("Buy", {120, 35}, 16, sf::Color::Green, sf::Color::Black);
  option1 =
      Button("Option1", {120, 35}, 16, sf::Color::Green, sf::Color::White);
  save = Button("Guardar", {120, 35}, 16, sf::Color::Green, sf::Color::White);
  close = Button("Close", {120, 35}, 16, sf::Color::Green, sf::Color::White);
  howTrade =
      Button("Info.Comprar", {140, 35}, 16, sf::Color::Green, sf::Color::White);
  howBuy = Button("Info.Intercambiar", {180, 35}, 16, sf::Color::Green,
                  sf::Color::White);
  progreessDiscovery =
      Button("Jugar", {35, 20}, 7, sf::Color::Green, sf::Color::White);
  progreessMonopoly =
      Button("Jugar", {37, 20}, 7, sf::Color::Green, sf::Color::White);
  dice = Button("Dado", {120, 50}, 15, sf::Color::Green, sf::Color::White);

  setButtonOrigins();
}

// Pasar a metodos aparte
void PlayView::setButtonOrigins() {

  p.setFont(font);
  p.setPosition({5, 15}, 3);
  p.buttonInOutColors(sf::Color(0, 0, 150, 255), sf::Color(0, 0, 220, 255),
                      view);
  p.buttonInOutColors(sf::Color(0, 0, 255, 255), sf::Color(0, 0, 225, 255),
                      view);

  turn.setFont(font);
  turn.setPosition({985, 600}, 3);
  turn.buttonInOutColors(sf::Color(0, 0, 150, 255), sf::Color(0, 0, 220, 255),
                         view);
  trade.setFont(font);
  trade.setPosition({20, 615}, 3);
  trade.buttonInOutColors(sf::Color(0, 0, 150, 255), sf::Color(0, 0, 220, 255),
                          view);

  option1.setFont(font);
  option1.setPosition({1120, 600}, 3);
  option1.buttonInOutColors(sf::Color(0, 0, 150, 255),
                            sf::Color(0, 0, 220, 255), view);

  save.setFont(font);
  save.setPosition({1120, 660}, 3);
  save.buttonInOutColors(sf::Color(0, 0, 150, 255), sf::Color(0, 0, 220, 255),
                         view);

  close.setFont(font);
  close.setPosition({985, 660}, 3);
  close.buttonInOutColors(sf::Color(0, 0, 150, 255), sf::Color(0, 0, 220, 255),
                          view);

  howTrade.setFont(font);
  howTrade.setPosition({1075, 465}, 3);
  howTrade.buttonInOutColors(sf::Color(0, 0, 150, 255),
                             sf::Color(0, 0, 220, 255), view);

  howBuy.setFont(font);
  howBuy.setPosition({1050, 425}, 3);
  howBuy.buttonInOutColors(sf::Color(0, 0, 150, 255), sf::Color(0, 0, 220, 255),
                           view);

  progreessDiscovery.setFont(font);
  progreessDiscovery.setPosition({738, 620}, 3);
  progreessDiscovery.buttonInOutColors(sf::Color(0, 0, 150, 255),
                                       sf::Color(0, 0, 220, 255), view);

  progreessMonopoly.setFont(font);
  progreessMonopoly.setPosition({775, 620}, 3);
  progreessMonopoly.buttonInOutColors(sf::Color(0, 0, 150, 255),
                                      sf::Color(0, 0, 220, 255), view);

  dice.setFont(font);
  dice.setPosition({1120, 600}, 3);
  dice.buttonInOutColors(sf::Color(0, 0, 150, 255), sf::Color(0, 0, 220, 255),
                         view);
}

void PlayView::createTurnButton() { turn.drawButton(view); }
void PlayView::createDiscoveryButton() { progreessDiscovery.drawButton(view); }
void PlayView::createMonopolyButton() { progreessMonopoly.drawButton(view); }
void PlayView::createInfoTradeButton() { howTrade.drawButton(view); }
void PlayView::createInfoBuyButton() { howBuy.drawButton(view); }
void PlayView::createTradeButton() { trade.drawButton(view); }
void PlayView::createPButton() { p.drawButton(view); }
void PlayView::createDiceButton() { dice.drawButton(view); }

void PlayView::isInfoBuyClicked(sf::Event event) {
  if (howBuy.isMouseOver(view)) {
    NoneAlert *alert = new NoneAlert(
        "Texto vacio", "1-Dar click en carta que quieres cambiar, dar al boton "
                       "trueque y seleccionar por cual la quieres cambiar.");
    alert->goView();
  }
}

void PlayView::isInfoTradeClicked(sf::Event event) {
  if (howTrade.isMouseOver(view)) {
    NoneAlert *alert = new NoneAlert(
        "Texto vacio", "1-Dar click en la imagen de carta situada a la "
                       "izquierda de la pantalla y situala en el tablero.\n");
    alert->goView();
  }
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
  loadRegisterButtons(howTrade);
  loadRegisterButtons(howBuy);
}

void PlayView::loadPlayersRectangle() {
  playerRectangle.setPosition(1020, 100);
  playerRectangle.setOutlineColor(sf::Color::White);
  playerRectangle.setSize({220, 300});
  playerRectangle.setFillColor(sf::Color(255, 255, 255, 128));
  drawRectangleShapes();
}

void PlayView::drawRectangleShapes() { view.draw(playerRectangle); }

void PlayView::loadRegisterButtons(Button &button) {
  if (button.isMouseOver(view)) {
    button.setBackgroundColor(sf::Color::White);
  } else {
    button.setBackgroundColor(sf::Color::Blue);

    if (isFourPlayers())
      createFourPlayersLabel();
  }
}

void PlayView::loadGameButtons() {
  loadPlayersRectangle();
  loadCardsRectangle();
  createDiscoveryButton();
  createMonopolyButton();
  createTradeButton();
  createTurnButton();
  createPButton();
  createDiceButton();
  createBuyRectangle();
}

/*methods of draw labels*/
void PlayView::drawLabelNumTurn() {
  createLabelNumTurn();
  if (isFirstTurn)
    view.draw(infoFisrtTurn.getTextInstance());
  view.draw(titleTurn.getTextInstance());
  view.draw(labelNumTurn.getTextInstance());
  view.draw(labelNumDice.getTextInstance());
  view.draw(numDevelopCard.getTextInstance());
  view.draw(ownerName.getTextInstance());
}

void PlayView::drawLabels() {
  createLabels();
  createLabelScorePlayer();
  view.draw(materialCard.getTextInstance());
  view.draw(developCard.getTextInstance());
  view.draw(pricingTable.getTextInstance());
  view.draw(turns.getTextInstance());
  view.draw(cards.getTextInstance());
  view.draw(titleScorePlayer.getTextInstance());
  view.draw(scorePlayer.getTextInstance());
  view.draw(road.getTextInstance());
  view.draw(city.getTextInstance());
  view.draw(town.getTextInstance());
}

void PlayView::drawLabelNamePlayers() {
  createLabelNamePlayers();
  if (isThreePlayers()) {
    view.draw(player1.getTextInstance());
    view.draw(player2.getTextInstance());
    view.draw(player3.getTextInstance());
  }
  if (isFourPlayers()) {
    view.draw(player1.getTextInstance());
    view.draw(player2.getTextInstance());
    view.draw(player3.getTextInstance());
    view.draw(player4.getTextInstance());
  }
}

void PlayView::drawLabelCardPlayer() {
  createLabelCardPlayer();
  view.draw(clayCard.getTextInstance());
  view.draw(mineralPlayerCard.getTextInstance());
  view.draw(wheatPlayerCard.getTextInstance());
  view.draw(woodPlayerCard.getTextInstance());
  view.draw(woolPlayerCard.getTextInstance());
}

void PlayView::drawLabelFigurePlayer() {
  createLabelFigurePlayer();
  view.draw(townPlayer.getTextInstance());
  view.draw(cityPlayer.getTextInstance());
  view.draw(roadPlayer.getTextInstance());
}

void PlayView::drawLabelDevelopCardPLayer() {
  createLabelPlayerDevelopCard();
  view.draw(knight.getTextInstance());
  view.draw(progress.getTextInstance());
  view.draw(victory.getTextInstance());
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
  roadIterator = (*game.playerIterator)->roads->begin();
  cityIterator = (*game.playerIterator)->citys->begin();
  townIterator = (*game.playerIterator)->towns->begin();
  if (townIterator != (*game.playerIterator)->towns->end())
    printImages((*townIterator)->getImagePath(), 590, 650);

  if (cityIterator != (*game.playerIterator)->citys->end())
    printImages((*cityIterator)->getImagePath(), 630, 650);

  if (roadIterator != (*game.playerIterator)->roads->end())
    printImages((*roadIterator)->getImagePath(), 680, 650);
}

/* methods for first turn*/
void PlayView::traverseLands(double x, double y) {
  it = landsList->begin();
  while (it != landsList->end()) {
    searhTown(x, y, it);
    it++;
  }
}

void PlayView::traverseLandsToAdjacentVertex(
    list<Vertex *>::iterator vIterator2) {
  list<Land *>::iterator itX = landsList->begin();
  while (itX != landsList->end()) {
    list<Vertex *>::iterator vIteratorAux;
    vIteratorAux = (*itX)->getTownsList()->begin();
    while (vIteratorAux != (*itX)->getTownsList()->end()) {
      parentAdjacentVertex(vIterator2, vIteratorAux);
      vIteratorAux++;
    }
    itX++;
  }
}

void PlayView::parentAdjacentVertex(list<Vertex *>::iterator vIterator2,
                                    list<Vertex *>::iterator vIteratorAux) {
  Edge *auxEdge =
      game.graph.getVertex((*vIteratorAux)->getVertexId())->firstEdge;
  while (auxEdge != nullptr) {
    if (game.graph.getVertex(auxEdge->destinyVertex->getVertexId())
                ->getVertexId() == (*vIterator2)->getVertexId() &&
        (game.graph.getVertex((*vIteratorAux)->getVertexId())->isClicked())) {
      isParentClicked = true;
    }
    auxEdge = auxEdge->next;
  }
}

bool PlayView::adjacentVertex(list<Vertex *>::iterator vIterator) {
  Edge *auxEdge = game.graph.getVertex((*vIterator)->getVertexId())->firstEdge;
  while (auxEdge != nullptr) {
    if (game.graph.getVertex(auxEdge->destinyVertex->getVertexId())
            ->isClicked()) {
      return true;
    } else {
      isAdjacentVertex = false;
    }
    auxEdge = auxEdge->next;
  }
  return isAdjacentVertex;
}

void PlayView::printTownPlayer(list<Vertex *>::iterator vIterator, int x,
                               int y) {
  if (game.graph.getVertex((*vIterator)->getVertexId())->getOwner() == NULL) {
    if (!adjacentVertex(vIterator)) {
      traverseLandsToAdjacentVertex(vIterator);
      if (!isParentClicked) {
        if ((*game.playerIterator)->getTownFirstTurn() < 2) {
          initializeIteratorTownList();
          setIsClickedToVertexGraph(vIterator);
          if (townIterator != (*game.playerIterator)->towns->end())
            printImages((*townIterator)->getImagePath(),
                        (*vIterator)->getTown()->getPosX(),
                        (*vIterator)->getTown()->getPosY());
          setOwnerToVertexGraph(
              game.graph.getVertex((*vIterator)->getVertexId()));
          deleteTowntoPlayer();
          (*game.playerIterator)->setScore(1);
          (*game.playerIterator)->setTownFirstTurn(1);
          if ((*game.playerIterator)->getTownFirstTurn() == 2) {
            receiveFirstMaterialCard();
          }
          game.graph.getVertex((*vIterator)->getVertexId())->setIsCity(false);
          game.graph.getVertex((*vIterator)->getVertexId())->setIsTown(true);

          view.display();
        } else {
          (*game.playerIterator)->setFirstTurnFinished(true);
          ErrorAlert *alert =
              new ErrorAlert("!ERROR!", "YA SELECCIONASTES 2 POBLADOS");
          alert->goView();
        }
      }
      isParentClicked = false;
    }
  }
}

void PlayView::searhTown(double x, double y, list<Land *>::iterator it) {
  list<Vertex *>::iterator vIterator;
  vIterator = (*it)->getTownsList()->begin();
  while (vIterator != (*it)->getTownsList()->end()) {
    if (isTownClicked(vIterator, x, y)) {
      if (isFirstTurn)
        printTownPlayer(vIterator, (int)x, (int)y);

      if (selectTown)
        buyTown(vIterator, (int)x, (int)y);

      if (selectCity)
        buyCity(vIterator, (int)x, (int)y);
    }
    vIterator++;
  }
}

void PlayView::buyCity(list<Vertex *>::iterator vIterator, double x, double y) {
  initializeIteratorCityList();
  if (game.graph.getVertex((*vIterator)->getVertexId())->getOwner() != NULL) {
    if (!game.graph.getVertex((*vIterator)->getVertexId())->getIsCity()) {
      if (game.graph.getVertex((*vIterator)->getVertexId())
              ->getOwner()
              ->getName() == (*playerIterator)->getName()) {
        if ((*game.playerIterator)->towns->size() > 1) { /// arreglar este BUG
          if (cityIterator != (*game.playerIterator)->citys->end())
            printImages((*cityIterator)->getImagePath(),
                        (*vIterator)->getTown()->getPosX(),
                        (*vIterator)->getTown()->getPosY());
          setOwnerToVertexGraph(
              game.graph.getVertex((*vIterator)->getVertexId()));
          deleteCitytoPlayer();
          addTownToPlayer();
          deleteCities();
          setIsClickedToVertexGraph(vIterator);
          (*game.playerIterator)->setScore(2);
          selectCity = false;
          game.graph.getVertex((*vIterator)->getVertexId())->setIsCity(true);
          game.graph.getVertex((*vIterator)->getVertexId())->setIsTown(false);
          view.display();
        }
      } else {
        ErrorAlert *alert =
            new ErrorAlert("!ERROR!", "EL POBLADO ES DE OTRO JUGADOR");
        alert->goView();
      }
    }
  }
}

void PlayView::addTownToPlayer() {
  initializeIteratorCityList();
  (*game.playerIterator)
      ->towns->push_back(new Town((*cityIterator)->getImagePath()));
}

void PlayView::buyTown(list<Vertex *>::iterator vIterator, double x, double y) {
  initializeIteratorTownList();
  if (!adjacentVertex(vIterator)) {
    if (game.graph.getVertex((*vIterator)->getVertexId())->getOwner() == NULL) {
      if ((*game.playerIterator)->towns->size() > 1) {
        if (townIterator != (*game.playerIterator)->towns->end())
          printImages((*townIterator)->getImagePath(),
                      (*vIterator)->getTown()->getPosX(),
                      (*vIterator)->getTown()->getPosY());
        setOwnerToVertexGraph(
            game.graph.getVertex((*vIterator)->getVertexId()));
        (*game.playerIterator)->setScore(1);
        setIsClickedToVertexGraph(vIterator);
        selectTown = false;
        deleteTowns();
        game.graph.getVertex((*vIterator)->getVertexId())->setIsCity(false);
        game.graph.getVertex((*vIterator)->getVertexId())->setIsTown(true);
        view.display();
      } else {
        ErrorAlert *alert = new ErrorAlert("!ERROR!", "POBLADOS INSUFICIENTES");
        alert->goView();
      }
    } else {
      ErrorAlert *alert = new ErrorAlert("!ERROR!", "POBLADO CON DUE??O");
      alert->goView();
    }
  }
}

void PlayView::receiveFirstMaterialCard() {
  list<Land *>::iterator it;
  it = landsList->begin();
  while (it != landsList->end()) {
    receiveFirstCard(it);
    it++;
  }
}

void PlayView::receiveFirstCard(list<Land *>::iterator it) {
  list<Vertex *>::iterator vIterator;
  vIterator = (*it)->getTownsList()->begin();
  while (isVertexesListTraversalInTurn(vIterator, it)) {
    if (existsAnOwnerInVertex(vIterator)) {
      if (isActualPlayerName(vIterator, game.playerIterator))
        giveCardsToPlayerFirstTurn(it);
    }
    vIterator++;
  }
}

/*others methods*/

list<Player *>::iterator PlayView::beginPlayerIterator() const {
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

void PlayView::createBuyRectangle() {
  buyRectangle.setSize({160, 80});
  buyRectangle.setPosition(160, 610);
  buyRectangle.setOutlineColor(sf::Color::White);
  buyRectangle.setFillColor(sf::Color(255, 255, 255, 128));
  view.draw(buyRectangle);
}

void PlayView::printPlayerBuyFigure() {
  cityIterator = (*game.playerIterator)->citys->begin();
  townIterator = (*game.playerIterator)->towns->begin();
  if (townIterator != (*game.playerIterator)->towns->end())
    printImages((*townIterator)->getImagePath(), 165, 615);

  if (cityIterator != (*game.playerIterator)->citys->end())
    printImages((*cityIterator)->getImagePath(), 280, 615);
}

void PlayView::loadBiggestArmyCard() {
  printImages("Images/extraCards/mini_biggestArmyCard.png", 210, 25);
}

void PlayView::printBuyDevelopCard() {
  printImages("Images/playerCard/mini_progressCard1.png", 210, 610);
  printImages("Images/playerCard/mini_knightCard1.png", 220, 610);
  printImages("Images/playerCard/mini_victoryPointCard1.png", 230, 610);
}

void PlayView::clickInDevelopCardBuy(int x, int y) {
  if (x > 210 && x < 270 && y > 610 && y < 670)
    buyView.goView();
}

void PlayView::clickTradeButton(sf::Event event) {
  if (trade.isPressed(event)) {
    tradeView.goView();
    traverseLandsToTrade();
    if (isPlayerNormalPortNeighbor || isPlayerSpecialPortNeighbor) {
      if (isPlayerNormalPortNeighbor)
        tradeNormal();

      if (isPlayerSpecialPortNeighbor)
        tradeSpecial();

    } else {
      tradePossible();
    }
  }
}

void PlayView::clickInTownBuy(int x, int y) {
  if (x > 165 && x < 165 + 30 && y > 615 && y < 615 + 30) {
    isTownBuyClicked = true;
    isCityBuyClicked = false;
  } else {
    isTownBuyClicked = false;
  }
}

void PlayView::clickInCityBuy(int x, int y) {
  if (x > 280 && x < 280 + 30 && y > 615 && y < 615 + 30) {
    isCityBuyClicked = true;
    isTownBuyClicked = false;
  } else {
    isCityBuyClicked = false;
  }
}

void PlayView::payRawMaterialsToBuyTown() {
  deleteClaytoPlayer();
  deleteWoodtoPlayer();
  deleteWooltoPlayer();
  deleteMineraltoPlayer();
  deleteWheattoPlayer();
  game.clayCards->push(new Clay);
  game.woodCards->push(new Wood);
  game.woolCards->push(new Wool);
  game.mineralCards->push(new Mineral);
  game.wheatCards->push(new Wheat);
  selectTown = true;
}

void PlayView::payRawMaterialsToBuyCity() {
  int iterator = 0;
  for (iterator; iterator < 3; iterator++) {
    deleteMineraltoPlayer();
    game.mineralCards->push(new Mineral());
    if (iterator < 1) {
      deleteWheattoPlayer();
      game.wheatCards->push(new Wheat());
    }
  }
  selectCity = true;
}

void PlayView::deleteClaytoPlayer() {
  clayIterator = (*game.playerIterator)->clayCard->begin();
  if (clayIterator != (*game.playerIterator)->clayCard->end())
    (*game.playerIterator)->clayCard->pop_back();
}

void PlayView::deleteWoodtoPlayer() {
  woodIterator = (*game.playerIterator)->woodCard->begin();
  if (woodIterator != (*game.playerIterator)->woodCard->end())
    (*game.playerIterator)->woodCard->pop_back();
}

void PlayView::deleteWooltoPlayer() {
  woolIterator = (*game.playerIterator)->woolCard->begin();
  if (woolIterator != (*game.playerIterator)->woolCard->end())
    (*game.playerIterator)->woolCard->pop_back();
}

void PlayView::deleteMineraltoPlayer() {
  mineralIterator = (*game.playerIterator)->mineralCard->begin();
  if (mineralIterator != (*game.playerIterator)->mineralCard->end())
    (*game.playerIterator)->mineralCard->pop_back();
}

void PlayView::deleteWheattoPlayer() {
  wheatIterator = (*game.playerIterator)->wheatlCard->begin();
  if (wheatIterator != (*game.playerIterator)->wheatlCard->end())
    (*game.playerIterator)->wheatlCard->pop_back();
}

// En algun momento este metodo se arreglara
void PlayView::receiveBoughtDevelopCard() {
  deleteWooltoPlayer();
  deleteWheattoPlayer();
  deleteMineraltoPlayer();
  game.mineralCards->push(new Mineral);
  game.wheatCards->push(new Wheat);
  game.woolCards->push(new Wool);
  if (buyView.isKnightButtonClicked || buyView.isProgress1ButtonClicked ||
      buyView.isVictoryButtonClicked || buyView.isProgress2ButtonClicked ||
      buyView.isProgress3ButtonClicked) {
    if (buyView.isKnightButtonClicked) {
      if (game.playerIterator != game.players->end()) {
        knightIterator = game.knightCards->begin();
        if (knightIterator != game.knightCards->end()) {
          (*game.playerIterator)->knightCards->push_back((*knightIterator));
          deleteKnightCard();
        }
      }
    }

    if (buyView.isProgress1ButtonClicked) {
      if (game.playerIterator != game.players->end()) {
        progressIterator = game.progressCards->begin();
        if (progressIterator != game.progressCards->end()) {
          (*game.playerIterator)->progressCards->push_back((*progressIterator));
          (*game.playerIterator)->setProgressDiscovery(2);
          deleteProgressCard((*progressIterator)->getType());
        }
      }
    }
    if (buyView.isProgress2ButtonClicked) {
      if (game.playerIterator != game.players->end()) {
        progressIterator = game.progressCards->begin();
        if (progressIterator != game.progressCards->end()) {
          (*game.playerIterator)->progressCards->push_back((*progressIterator));
          deleteProgressCard((*progressIterator)->getType());
        }
      }
    }
    if (buyView.isProgress3ButtonClicked) {
      if (game.playerIterator != game.players->end()) {
        progressIterator = game.progressCards->begin();
        if (progressIterator != game.progressCards->end()) {
          (*game.playerIterator)->progressCards->push_back((*progressIterator));
          (*game.playerIterator)->progressMonopoly = new Progress();
          deleteProgressCard((*progressIterator)->getType());
          isMonopolyBuy = true;
        }
      }
    }
    if (buyView.isVictoryButtonClicked) {
      (*game.playerIterator)
          ->victoryPointsCards->push_back((*game.victoryPointCards->begin()));
      if (game.playerIterator != game.players->end()) {
        victoryPointsIterator = game.victoryPointCards->begin();
        if (victoryPointsIterator != game.victoryPointCards->end()) {
          (*game.playerIterator)
              ->victoryPointsCards->push_back((*victoryPointsIterator));
          deleteVictoryCard();
        }
      }
    }
  } else {
    ErrorAlert *alert = new ErrorAlert(
        "!ERROR!",
        "NO SE HA SELECCIONADO NINGUNA CARTA DE DESARROLLO POR COMPRAR");
    alert->goView();
  }
}

void PlayView::deleteKnightCard() { game.knightCards->pop_back(); }
void PlayView::deleteVictoryCard() { game.victoryPointCards->pop_back(); }

void PlayView::deleteProgressCard(int type) {
  while (progressIterator != game.progressCards->end()) {
    if ((*progressIterator)->getType() == type)
      game.progressCards->erase(progressIterator);
    break;
  }
}

void PlayView::buildTown() {
  if ((*game.playerIterator)->clayCard->size() >= 1 &&
      (*game.playerIterator)->woodCard->size() >= 1 &&
      (*game.playerIterator)->wheatlCard->size() >= 1 &&
      (*game.playerIterator)->woolCard->size() >= 1) {
    payRawMaterialsToBuyTown();
  } else {
    ErrorAlert *alert =
        new ErrorAlert("!ERROR!", "MATERIAS PRIMAS INSUFICIENTES");
    alert->goView();
  }
}

void PlayView::buyDevelopCard() {
  if ((*game.playerIterator)->mineralCard->size() >= 1 &&
      (*game.playerIterator)->wheatlCard->size() >= 1 &&
      (*game.playerIterator)->woolCard->size() >= 1) {
    receiveBoughtDevelopCard();
    buyView.isBuyClicked = false;
  } else {
    ErrorAlert *alert =
        new ErrorAlert("!ERROR!", "MATERIAS PRIMAS INSUFICIENTES");
    alert->goView();
    buyView.isBuyClicked = false;
  }
}

void PlayView::buildCity() {
  if ((*game.playerIterator)->wheatlCard->size() >= 2 &&
      ((*game.playerIterator)->mineralCard->size() >= 3)) {
    payRawMaterialsToBuyCity();
  } else {
    ErrorAlert *alert =
        new ErrorAlert("!ERROR!", "MATERIAS PRIMAS INSUFICIENTES");
    alert->goView();
  }
}

void PlayView::isBuyButtonClicked(sf::Event event) {
  if (isTownBuyClicked)
    buildTown();

  if (isCityBuyClicked)
    buildCity();

  if (buyView.isBuyClicked)
    buyDevelopCard();
}

void PlayView::loadOcean() {
  OceanImg.loadFromFile("Images/Muelle/Ocean.png");
  OCeanSprite.setTexture(OceanImg);
  OCeanSprite.setPosition({400, 0});
  view.draw(OCeanSprite);
}

void PlayView::drawView() {
  clearView();
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
  drawLabelDevelopCardPLayer();
  drawLabelMaterialGame();
  printPlayerFigure();
  printPlayerDevelopCard();
  printFiguresGame();
  createButtons();
  printPlayerBuyFigure();
  printBuyDevelopCard();
  loadBiggestArmyCard();
  game.getLandsNumbersRandomized();
  game.setNumbersToLands(landsList);
  printLandsDiceNumbers();
  displayView();
}

void PlayView::initializeIteratorTownList() {
  townIterator = (*game.playerIterator)->towns->begin();
}

void PlayView::initializeIteratorCityList() {
  cityIterator = (*game.playerIterator)->citys->begin();
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
  if ((*landIterator)->getTypeLand() == "Mountain") {
    if (deleteMineralCards())
      (*game.playerIterator)->mineralCard->push_back(new Mineral());
  }
  if ((*landIterator)->getTypeLand() == "Brick") {
    if (deleteClayCards())
      (*game.playerIterator)->clayCard->push_back(new Clay());
  }
  if ((*landIterator)->getTypeLand() == "Forest") {
    if (deleteWoodCards())
      (*game.playerIterator)->woodCard->push_back(new Wood());
  }
  if ((*landIterator)->getTypeLand() == "Grass") {
    if (deleteWoolCards())
      (*game.playerIterator)->woolCard->push_back(new Wool());
  }
  if ((*landIterator)->getTypeLand() == "Field") {
    if (deleteWheatCards())
      (*game.playerIterator)->wheatlCard->push_back(new Wheat());
  }
}

void PlayView::firstTurn() {
  playerIterator = beginPlayerIterator();
  while (isPlayerListTraversal()) {
    if ((*playerIterator)->getTownFirstTurn() == 2)
      isFirstTurn = false;
    else
      isFirstTurn = true;

    playerIterator++;
  }
}

void PlayView::deleteTowns() {
  townIterator = game.getTownsList()->begin();
  if (townIterator != game.getTownsList()->end())
    game.getTownsList()->pop_back(); // poner alerta aca
}

void PlayView::deleteCities() {
  cityIterator = game.getCitiesList()->begin();
  if (cityIterator != game.getCitiesList()->end())
    game.getTownsList()->pop_back(); // poner alerta aca
}

void PlayView::deleteTowntoPlayer() {
  if (townIterator != (*game.playerIterator)->towns->end())
    (*game.playerIterator)->towns->pop_back(); // poner alerta aca
}

void PlayView::deleteCitytoPlayer() {
  if (cityIterator != (*game.playerIterator)->citys->end())
    (*game.playerIterator)->citys->pop_back(); // poner alerta aca
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
  game.makeMaterialCard();
  game.makeFigures();
  game.makeDevelopCard();
  landsList = game.getLandsList();
  game.assignTownsToLand();
  game.makeGraph();
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
        view.waitEvent(eventTest);
      case sf::Event::MouseButtonPressed:
        if (eventTest.MouseButtonPressed && isMouseLeftClicked(eventTest)) {
          if (isFirstTurn) {
            firstTraversalLand();
          } else {
            hexagonsMethod();
            isDiceButtonClicked(event);
            resourcesMethod();
            progressMethod();
            shopMethod();
            largestArmy();
            clickTradeButton(eventTest);
          }
          eventPlayerMethod();
          isInfoBuyClicked(event);
          isInfoTradeClicked(event);
          if (isClosePressed())
            closeView();
          break;

        case sf::Event::Closed:
          closeView();
          break;
        }
        break;
      }
      drawView();
    }
  }
}

bool PlayView::isClosePressed() { return (close.isPressed(event)); }

void PlayView::firstTraversalLand() {
  traverseLands(getMousePositionX(view), getMousePositionY(view));
}

void PlayView::largestArmy() {
  if (!(*game.playerIterator)->getTheLargestArmy()) {
    if (theLargestArmy()) {
      ownerBiggestArmy = (*game.playerIterator)->getName();
      (*game.playerIterator)->setScore(2);
    }
    istheLargestArmy = false;
  }
}

void PlayView::shopMethod() {
  if (getMousePositionX(view) > 145 && getMousePositionX(view) < 330 &&
      getMousePositionY(view) > 570 && getMousePositionY(view) < 685) {
    clickInCityBuy(getMousePositionX(view), getMousePositionY(view));
    clickInTownBuy(getMousePositionX(view), getMousePositionY(view));
    clickInDevelopCardBuy(getMousePositionX(view), getMousePositionY(view));
    isBuyButtonClicked(eventTest);
  }
}

void PlayView::hexagonsMethod() {
  if (isHexagonsClicked(static_cast<float>(getMousePositionX(view)),
                        static_cast<float>(getMousePositionY(view))))
    traverseLands(static_cast<double>(getMousePositionX(view)),
                  static_cast<double>(getMousePositionY(view)));
}

void PlayView::resourcesMethod() {
  if (isMaterialClick(static_cast<float>(getMousePositionX(view)),
                      static_cast<float>(getMousePositionY(view))))
    checkMaterialClicks();
}

void PlayView::progressMethod() {
  if (isProgressClick(static_cast<float>(getMousePositionX(view)),
                      static_cast<float>(getMousePositionY(view)))) {
    playDiscoveryCard(eventTest);
    playMonopolyCard(eventTest);
  }
}

void PlayView::eventPlayerMethod() {
  if (isRightClicked(static_cast<float>(getMousePositionX(view)),
                     static_cast<float>(getMousePositionY(view)))) {
    isTurnButtonClicked(getMousePositionX(view), getMousePositionY(view));
  }
}

bool PlayView::isRightClicked(float x, float y) {
  return (x > 975 && x < 1265 && y > 575 && y < 690);
}

bool PlayView::isHexagonsClicked(float x, float y) {
  return (x > 435 && x < 955 && y > 5 && y < 475);
}

bool PlayView::isProgressClick(float x, float y) {
  return (x > 730 && x < 945 && y > 600 && y < 695);
}

bool PlayView::isMaterialClick(float x, float y) {
  return (x > 350 && x < 570 && y > 600 && y < 690);
}

void PlayView::checkMaterialClicks() {
  clickClayTrade(getMousePositionX(view), getMousePositionY(view));
  clickWheatTrade(getMousePositionX(view), getMousePositionY(view));
  clickWoolTrade(getMousePositionX(view), getMousePositionY(view));
  clickWoodTrade(getMousePositionX(view), getMousePositionY(view));
  clickMineralTrade(getMousePositionX(view), getMousePositionY(view));
}

void PlayView::isDiceButtonClicked(sf::Event event) {
  if (dice.isPressed(event)) {
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

bool PlayView::isActualPlayerName(list<Vertex *>::iterator vertexIterator,
                                  list<Player *>::iterator player) {
  return (game.graph.getVertex((*vertexIterator)->getVertexId())
              ->getOwner()
              ->getName() == (*player)->getName());
}

bool PlayView::deleteWoodCards() {
  if (game.woodCards->size() > 1) {
    game.woodCards->pop();
    return true;
  }
  return false;
}

bool PlayView::deleteWoolCards() {
  if (game.woolCards->size() > 1) {
    game.woolCards->pop();
    return true;
  }
  return false;
}

bool PlayView::deleteMineralCards() {
  if (game.mineralCards->size() > 1) {
    game.mineralCards->pop();
    return true;
  }
  return false;
}

bool PlayView::deleteClayCards() {
  if (game.clayCards->size() > 1) {
    game.clayCards->pop();
    return true;
  }
  return false;
}

bool PlayView::deleteWheatCards() {
  if (game.wheatCards->size() > 1) {
    game.wheatCards->pop();
    return true;
  }
  return false;
}

void PlayView::giveCardsToPlayerCity(list<Land *>::iterator landIterator) {
  if ((*landIterator)->getTypeLand() == "Mountain") {
    if (deleteMineralCards() && deleteMineralCards()) {
      (*playerIterator)->mineralCard->push_back(new Mineral());
      (*playerIterator)->mineralCard->push_back(new Mineral());
    }
  }
  if ((*landIterator)->getTypeLand() == "Brick") {
    if (deleteClayCards() && deleteClayCards()) {
      (*playerIterator)->clayCard->push_back(new Clay());
      (*playerIterator)->clayCard->push_back(new Clay());
    }
  }
  if ((*landIterator)->getTypeLand() == "Forest") {
    if (deleteWoodCards() && deleteWoodCards()) {
      (*playerIterator)->woodCard->push_back(new Wood());
      (*playerIterator)->woodCard->push_back(new Wood());
    }
  }
  if ((*landIterator)->getTypeLand() == "Grass") {
    if (deleteWoolCards() && deleteWoolCards()) {
      (*playerIterator)->woolCard->push_back(new Wool());
      (*playerIterator)->woolCard->push_back(new Wool());
    }
  }
  if ((*landIterator)->getTypeLand() == "Field") {
    if (deleteWheatCards() && deleteWheatCards()) {
      (*playerIterator)->wheatlCard->push_back(new Wheat());
      (*playerIterator)->wheatlCard->push_back(new Wheat());
    }
  }
}

void PlayView::giveCardsToPlayer(list<Land *>::iterator landIterator) {
  if ((*landIterator)->getTypeLand() == "Mountain") {
    if (deleteMineralCards())
      (*playerIterator)->mineralCard->push_back(new Mineral());
  }
  if ((*landIterator)->getTypeLand() == "Brick") {
    if (deleteClayCards())
      (*playerIterator)->clayCard->push_back(new Clay());
  }
  if ((*landIterator)->getTypeLand() == "Forest") {
    if (deleteWoodCards())
      (*playerIterator)->woodCard->push_back(new Wood());
  }
  if ((*landIterator)->getTypeLand() == "Grass") {
    if (deleteWoolCards())
      (*playerIterator)->woolCard->push_back(new Wool());
  }
  if ((*landIterator)->getTypeLand() == "Field") {
    if (deleteWheatCards())
      (*playerIterator)->wheatlCard->push_back(new Wheat());
  }
}

void PlayView::receiveCard(list<Land *>::iterator it) {
  list<Vertex *>::iterator vIterator;
  vIterator = (*it)->getTownsList()->begin();
  playerIterator = beginPlayerIterator();
  while (isPlayerListTraversal()) {
    while (isVertexesListTraversalInTurn(vIterator, it)) {
      if (existsAnOwnerInVertex(vIterator)) {
        if (isActualPlayerName(vIterator, playerIterator)) {
          if (game.graph.getVertex((*vIterator)->getVertexId())->getIsCity())
            giveCardsToPlayerCity(it);
          if (game.graph.getVertex((*vIterator)->getVertexId())->getIsTown())
            giveCardsToPlayer(it);
        }
      }
      vIterator++;
    }
    vIterator = (*it)->getTownsList()->begin();
    playerIterator++;
  }
}

void PlayView::receiveMaterialCard(int numDice) {
  list<Land *>::iterator it;
  it = landsList->begin();
  while (it != landsList->end()) {
    if ((*it)->getDiceNumber() == numDice) {
      receiveCard(it);
      break;
    }
    it++;
  }
}

void PlayView::saveMatchActualState() {
  FileHandler fileHandler;
  //  fileHandler.saveFile(getFullPathMatchName(actualMatchName), game);
  log(actualMatchName);
}

void PlayView::isTurnButtonClicked(int x, int y) {
  if (turn.isMouseOver(view)) {
    /*   saveMatchActualState();*/
    if (game.playerIterator != game.players->end()) {
      if ((*game.playerIterator)->getScore() >= 10) {
        NoneAlert *alert =
            new NoneAlert("!FELICIDADES! " + (*game.playerIterator)->getName(),
                          " JUEGO GANADO");
        alert->goView();
        closeView();
      } else {
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
}

void PlayView::compareBiggestArmyPlayer() {
  playerIterator = game.players->begin();
  int cont = 0;
  while (playerIterator != game.players->end()) {
    if ((*playerIterator)->getName() != (*game.playerIterator)->getName()) {
      if (!(*game.playerIterator)->getTheLargestArmy()) {
        if ((*game.playerIterator)->knightCards->size() >
            (*playerIterator)->knightCards->size()) {
          cont++;
          (*playerIterator)->setTheLargestArmy(false);
        }
      }
    }
    playerIterator++;
  }
  if (cont == game.players->size() - 1) {
    (*game.playerIterator)->setTheLargestArmy(true);
    istheLargestArmy = true;
  }
}

bool PlayView::theLargestArmy() {
  if ((*game.playerIterator)->knightCards->size() >= 3)
    compareBiggestArmyPlayer();

  return istheLargestArmy;
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

void PlayView::drawTurn(int turns, int posiI) {}

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

bool PlayView::isDessertLand(list<Land *>::iterator landIterator) {
  return ((*landIterator)->getTypeLand() == dessertType);
}

void PlayView::createLabelDiceNumber(list<Land *>::iterator landIterator) {
  if (!isDessertLand(landIterator))
    createTempNumber(landIterator);

  if (isDessertLand(landIterator))
    createTempNumberEmpty(landIterator);

  view.draw(tempNumber.getTextInstance());
}

void PlayView::createTempNumberEmpty(list<Land *>::iterator landIterator) {
  printImages("Images/Figures/thief.png", (*landIterator)->getPosX() + 32,
              (*landIterator)->getPosY() + 25);
}

void PlayView::createTempNumber(list<Land *>::iterator landIterator) {
  tempNumber = Label(std::to_string((*landIterator)->getDiceNumber()),
                     sf::Color::Black, font, sf::Text::Bold, 22,
                     static_cast<float>((*landIterator)->getPosX() + 45),
                     static_cast<float>((*landIterator)->getPosY() + 35));
}

void PlayView::printLandsDiceNumbers() {
  list<Land *>::iterator landIterator;
  landIterator = landsList->begin();
  while (landIterator != landsList->end()) {
    createLabelDiceNumber(landIterator);
    landIterator++;
  }
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
    if (game.graph.getVertex((*itX)->getVertexId())->getIsTown()) {
      townIterator = game.graph.getVertex((*itX)->getVertexId())
                         ->getOwner()
                         ->towns->begin();
      if (townIterator != game.graph.getVertex((*itX)->getVertexId())
                              ->getOwner()
                              ->towns->end()) {
        printImages((*townIterator)->getImagePath(), relativePositionX,
                    relativePositionY);
      }
    }
    if (game.graph.getVertex((*itX)->getVertexId())->getIsCity()) {
      cityIterator = game.graph.getVertex((*itX)->getVertexId())
                         ->getOwner()
                         ->citys->begin();
      if (cityIterator != game.graph.getVertex((*itX)->getVertexId())
                              ->getOwner()
                              ->citys->end()) {
        printImages((*cityIterator)->getImagePath(), relativePositionX,
                    relativePositionY);
      }
    }
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
  if (isMouseLeftClicked(event)) {
    log("mouse x: " << event.mouseButton.x);
    log("mouse y: " << event.mouseButton.y);
  }
}

////////TRADE//////////
///////TRADE//////////
///////TRADE//////////
void PlayView::clickMineralTrade(int x, int y) {
  if (x > 400 && x < 400 + 40 && y > 640 && y < 640 + 40) {
    isCLayTradeClicked = false;
    isMineralTradeClicked = true;
    isWoolTradeClicked = false;
    isWoodTradeClicked = false;
    isWheatTradeClicked = false;
  }
}

void PlayView::clickWoodTrade(int x, int y) {
  if (x > 480 && x < 480 + 40 && y > 640 && y < 640 + 40) {
    isCLayTradeClicked = false;
    isMineralTradeClicked = false;
    isWoolTradeClicked = false;
    isWoodTradeClicked = true;
    isWheatTradeClicked = false;
  }
}

void PlayView::clickWoolTrade(int x, int y) {
  if (x > 520 && x < 520 + 40 && y > 640 && y < 640 + 40) {
    isCLayTradeClicked = false;
    isMineralTradeClicked = false;
    isWoolTradeClicked = true;
    isWoodTradeClicked = false;
    isWheatTradeClicked = false;
  }
}

void PlayView::clickWheatTrade(int x, int y) {
  if (x > 440 && x < 440 + 40 && y > 640 && y < 640 + 40) {
    isCLayTradeClicked = false;
    isMineralTradeClicked = false;
    isWoolTradeClicked = false;
    isWoodTradeClicked = false;
    isWheatTradeClicked = true;
  }
}

void PlayView::clickClayTrade(int x, int y) {
  if (x > 360 && x < 360 + 40 && y > 640 && y < 640 + 40) {
    isCLayTradeClicked = true;
    isMineralTradeClicked = false;
    isWoolTradeClicked = false;
    isWoodTradeClicked = false;
    isWheatTradeClicked = false;
  }
}

void PlayView::traverseLandsToTrade() {
  it = landsList->begin();
  while (it != landsList->end()) {
    townsInPort(it);
    it++;
  }
}

void PlayView::townsInPort(list<Land *>::iterator it) {
  list<Vertex *>::iterator vIterator;
  vIterator = (*it)->getTownsList()->begin();
  while (vIterator != (*it)->getTownsList()->end()) {
    if (landIsNormalPortNeighbor(it)) {
      if (townIsNormalPortNeighbor(vIterator)) {
        if (game.graph.getVertex((*vIterator)->getVertexId())->getOwner() !=
            NULL) {
          if (game.graph.getVertex((*vIterator)->getVertexId())
                  ->getOwner()
                  ->getName() == (*game.playerIterator)->getName()) {
            isPlayerNormalPortNeighbor = true;
            isPlayerSpecialPortNeighbor = false;
          }
        }
      }
    }

    if (landIsSpecialPortNeighbor(it)) {
      if (townIsSpecialPortNeighbor(vIterator)) {
        if (game.graph.getVertex((*vIterator)->getVertexId())->getOwner() !=
            NULL) {
          if (game.graph.getVertex((*vIterator)->getVertexId())
                  ->getOwner()
                  ->getName() == // no son mismos nombres
              (*game.playerIterator)->getName()) {
            isPlayerSpecialPortNeighbor = true;
            isPlayerNormalPortNeighbor = false;
          }
        }
      }
    }
    vIterator++;
  }
}

bool PlayView::townIsNormalPortNeighbor(list<Vertex *>::iterator vIterator) {
  return (
      (*vIterator)->getVertexId() == 1 || (*vIterator)->getVertexId() == 4 ||
      (*vIterator)->getVertexId() == 16 || (*vIterator)->getVertexId() == 27 ||
      (*vIterator)->getVertexId() == 33 || (*vIterator)->getVertexId() == 48 ||
      (*vIterator)->getVertexId() == 52);
}

bool PlayView::townIsSpecialPortNeighbor(list<Vertex *>::iterator vIterator) {
  return (
      (*vIterator)->getVertexId() == 2 || (*vIterator)->getVertexId() == 6 ||
      (*vIterator)->getVertexId() == 17 || (*vIterator)->getVertexId() == 12 ||
      (*vIterator)->getVertexId() == 34 || (*vIterator)->getVertexId() == 39 ||
      (*vIterator)->getVertexId() == 43 || (*vIterator)->getVertexId() == 47 ||
      (*vIterator)->getVertexId() == 50 || (*vIterator)->getVertexId() == 53);
}

bool PlayView::landIsNormalPortNeighbor(list<Land *>::iterator it) {
  return ((*it)->getLandId() == 1 || (*it)->getLandId() == 7 ||
          (*it)->getLandId() == 12 || (*it)->getLandId() == 17);
}

bool PlayView::landIsSpecialPortNeighbor(list<Land *>::iterator it) {
  return ((*it)->getLandId() == 2 || (*it)->getLandId() == 4 ||
          (*it)->getLandId() == 13 || (*it)->getLandId() == 19 ||
          (*it)->getLandId() == 16 || (*it)->getLandId() == 18);
}

void PlayView::tradeCard() {
  if (tradeView.isCLayButtonClicked)
    (*game.playerIterator)->clayCard->push_back(new Clay());
  if (tradeView.isMineralButtonClicked)
    (*game.playerIterator)->mineralCard->push_back(new Mineral());
  if (tradeView.isWheatButtonClicked)
    (*game.playerIterator)->wheatlCard->push_back(new Wheat());
  if (tradeView.isWoodButtonClicked)
    (*game.playerIterator)->woodCard->push_back(new Wood());
  if (tradeView.isWoolButtonClicked)
    (*game.playerIterator)->woolCard->push_back(new Wool());
}

void PlayView::tradePossible() {
  int iterator = 0;
  if (isCLayTradeClicked || isWoodTradeClicked || isWoolTradeClicked ||
      isWheatTradeClicked || isMineralTradeClicked) {
    if (isCLayTradeClicked) {
      for (iterator; iterator < 4; iterator++) {
        deleteClaytoPlayer();
        game.clayCards->push(new Clay);
      }
      tradeCard();
    }
    if (isWoodTradeClicked) {
      for (iterator; iterator < 4; iterator++) {
        deleteWoodtoPlayer();
        game.woodCards->push(new Wood);
      }
      tradeCard();
    }
    if (isWoolTradeClicked) {
      for (iterator; iterator < 4; iterator++) {
        deleteWooltoPlayer();
        game.woolCards->push(new Wool);
      }
      tradeCard();
    }
    if (isWheatTradeClicked) {
      for (iterator; iterator < 4; iterator++) {
        deleteWheattoPlayer();
        game.wheatCards->push(new Wheat);
      }
      tradeCard();
    }
    if (isMineralTradeClicked) {
      for (iterator; iterator < 4; iterator++) {
        deleteMineraltoPlayer();
        game.mineralCards->push(new Mineral);
      }
      tradeCard();
    }
  } else {
    ErrorAlert *alert = new ErrorAlert(
        "!ERROR!", "NO SE HA SELECCIONADO NINGUNA MATERIA PRIMA");
    alert->goView();
  }
}

void PlayView::tradeNormal() {
  int iterator = 0;
  if (isCLayTradeClicked || isWoodTradeClicked || isWoolTradeClicked ||
      isWheatTradeClicked || isMineralTradeClicked) {
    if (isCLayTradeClicked) {
      for (iterator; iterator < 3; iterator++) {
        deleteClaytoPlayer();
        game.clayCards->push(new Clay);
      }
      tradeCard();
    }
    if (isWoodTradeClicked) {
      for (iterator; iterator < 3; iterator++) {
        deleteWoodtoPlayer();
        game.woodCards->push(new Wood);
      }
      tradeCard();
    }
    if (isWoolTradeClicked) {
      for (iterator; iterator < 3; iterator++) {
        deleteWooltoPlayer();
        game.woolCards->push(new Wool);
      }
      tradeCard();
    }
    if (isWheatTradeClicked) {
      for (iterator; iterator < 3; iterator++) {
        deleteWheattoPlayer();
        game.wheatCards->push(new Wheat);
      }
      tradeCard();
    }
    if (isMineralTradeClicked) {
      for (iterator; iterator < 3; iterator++) {
        deleteMineraltoPlayer();
        game.mineralCards->push(new Mineral);
      }
      tradeCard();
    }
  } else {
    ErrorAlert *alert = new ErrorAlert(
        "!ERROR!", "NO SE HA SELECCIONADO NINGUNA MATERIA PRIMA");
    alert->goView();
  }
}

void PlayView::tradeSpecial() {
  int iterator = 0;
  if (isCLayTradeClicked || isWoodTradeClicked || isWoolTradeClicked ||
      isWheatTradeClicked || isMineralTradeClicked) {
    if (isCLayTradeClicked) {
      for (iterator; iterator < 2; iterator++) {
        deleteClaytoPlayer();
        game.clayCards->push(new Clay);
      }
      tradeCard();
    }
    if (isWoodTradeClicked) {
      for (iterator; iterator < 2; iterator++) {
        deleteWoodtoPlayer();
        game.woodCards->push(new Wood);
      }
      tradeCard();
    }
    if (isWoolTradeClicked) {
      for (iterator; iterator < 2; iterator++) {
        deleteWooltoPlayer();
        game.woolCards->push(new Wool);
      }
      tradeCard();
    }
    if (isWheatTradeClicked) {
      for (iterator; iterator < 2; iterator++) {
        deleteWheattoPlayer();
        game.wheatCards->push(new Wheat);
      }
      tradeCard();
    }
    if (isMineralTradeClicked) {
      for (iterator; iterator < 2; iterator++) {
        deleteMineraltoPlayer();
        game.mineralCards->push(new Mineral);
      }
      tradeCard();
    }
  } else {
    ErrorAlert *alert = new ErrorAlert(
        "!ERROR!", "NO SE HA SELECCIONADO NINGUNA MATERIA PRIMA");
    alert->goView();
  }
}

////////PLAY DEVELOP CARD//////////
///////PLAY DEVELOP CARD//////////
///////PLAY DEVELOP CARD//////////
void PlayView::playDiscoveryCard(sf::Event event) {
  if (progreessDiscovery.isPressed(event)) {
    if ((*game.playerIterator)->getProgressDiscovery() > 0) {
      if (isCLayTradeClicked || isWoodTradeClicked || isWoolTradeClicked ||
          isWheatTradeClicked || isMineralTradeClicked) {
        if (isCLayTradeClicked) {
          if (deleteClayCards())
            (*game.playerIterator)->clayCard->push_back(new Clay());
          (*game.playerIterator)->restProgressDiscovery(1);
        }
        if (isWoodTradeClicked) {
          if (deleteWoodCards())
            (*game.playerIterator)->woodCard->push_back(new Wood());
          (*game.playerIterator)->restProgressDiscovery(1);
        }
        if (isWoolTradeClicked) {
          if (deleteWoolCards())
            (*game.playerIterator)->woolCard->push_back(new Wool());
          (*game.playerIterator)->restProgressDiscovery(1);
        }
        if (isWheatTradeClicked) {
          if (deleteWheatCards())
            (*game.playerIterator)->wheatlCard->push_back(new Wheat());
          (*game.playerIterator)->restProgressDiscovery(1);
        }
        if (isMineralTradeClicked) {
          if (deleteMineralCards())
            (*game.playerIterator)->mineralCard->push_back(new Mineral());
          (*game.playerIterator)->restProgressDiscovery(1);
        }
      }
    }
    game.progressCards->pop_back();
  }
}

void PlayView::playMonopolyCard(sf::Event event) {
  if (progreessMonopoly.isPressed(event)) {
    if ((*game.playerIterator)->progressMonopoly != nullptr) {
      if (isCLayTradeClicked || isWoodTradeClicked || isWoolTradeClicked ||
          isWheatTradeClicked || isMineralTradeClicked) {
        if (isCLayTradeClicked) {
          getClaysPlayersToMonopoly();
          (*game.playerIterator)->progressMonopoly = nullptr;
          (*game.playerIterator)->progressCards->pop_back();
        }
        if (isWoodTradeClicked) {
          getWoodsPlayersToMonopoly();
          (*game.playerIterator)->progressMonopoly = nullptr;
          (*game.playerIterator)->progressCards->pop_back();
        }
        if (isWoolTradeClicked) {
          getWoolsPlayersToMonopoly();
          (*game.playerIterator)->progressMonopoly = nullptr;
          (*game.playerIterator)->progressCards->pop_back();
        }
        if (isWheatTradeClicked) {
          getWheatsPlayersToMonopoly();
          (*game.playerIterator)->progressMonopoly = nullptr;
          (*game.playerIterator)->progressCards->pop_back();
        }
        if (isMineralTradeClicked) {
          getMineralsPlayersToMonopoly();
          (*game.playerIterator)->progressMonopoly = nullptr;
          (*game.playerIterator)->progressCards->pop_back();
        }
      }
    }
  }
}

void PlayView::getClaysPlayersToMonopoly() {
  int iterator = 0;
  playerIterator = game.players->begin();
  while (playerIterator != game.players->end()) {
    if ((*playerIterator)->getName() != (*game.playerIterator)->getName()) {
      std::size_t sizeList = (*playerIterator)->clayCard->size();
      while (iterator < sizeList) {
        (*playerIterator)->clayCard->pop_back();
        (*game.playerIterator)->clayCard->push_back(new Clay());
        iterator++;
      }
    }
    iterator = 0;
    playerIterator++;
  }
}

void PlayView::getWoodsPlayersToMonopoly() {
  int iterator = 0;
  playerIterator = game.players->begin();
  while (playerIterator != game.players->end()) {
    if ((*playerIterator)->getName() != (*game.playerIterator)->getName()) {
      std::size_t sizeList = (*playerIterator)->woodCard->size();
      while (iterator < sizeList) {
        (*playerIterator)->woodCard->pop_back();
        (*game.playerIterator)->woodCard->push_back(new Wood());
        iterator++;
      }
    }
    iterator = 0;
    playerIterator++;
  }
}

void PlayView::getWoolsPlayersToMonopoly() {
  int iterator = 0;
  playerIterator = game.players->begin();
  while (playerIterator != game.players->end()) {
    if ((*playerIterator)->getName() != (*game.playerIterator)->getName()) {
      std::size_t sizeList = (*playerIterator)->woolCard->size();
      while (iterator < sizeList) {
        (*playerIterator)->woolCard->pop_back();
        (*game.playerIterator)->woolCard->push_back(new Wool());
        iterator++;
      }
    }
    iterator = 0;
    playerIterator++;
  }
}

void PlayView::getMineralsPlayersToMonopoly() {
  int iterator = 0;
  playerIterator = game.players->begin();
  while (playerIterator != game.players->end()) {
    if ((*playerIterator)->getName() != (*game.playerIterator)->getName()) {
      std::size_t sizeList = (*playerIterator)->mineralCard->size();
      while (iterator < sizeList) {
        (*playerIterator)->mineralCard->pop_back();
        (*game.playerIterator)->mineralCard->push_back(new Mineral());
        iterator++;
      }
    }
    iterator = 0;
    playerIterator++;
  }
}

void PlayView::getWheatsPlayersToMonopoly() {
  int iterator = 0;
  playerIterator = game.players->begin();
  while (playerIterator != game.players->end()) {
    if ((*playerIterator)->getName() != (*game.playerIterator)->getName()) {
      std::size_t sizeList = (*playerIterator)->wheatlCard->size();
      while (iterator < sizeList) {
        (*playerIterator)->wheatlCard->pop_back();
        (*game.playerIterator)->wheatlCard->push_back(new Wheat());
        iterator++;
      }
    }
    iterator = 0;
    playerIterator++;
  }
}