#include "Window.hpp"

sf::Event event;

void Window::goTitleView() {
	sf::Font font;
	sf::RenderWindow titleWindow(sf::VideoMode(1280, 720), "Main Menu");
	this->actualWindow = &titleWindow;
	sf::Texture titleImage;
	titleImage.loadFromFile("Images/inicio.jpg");
	sf::Sprite titleSprite(titleImage);
	font.loadFromFile("mononoki.ttf");
	Label* title = new Label("Catan", sf::Color::Black, font, sf::Text::Bold, 100,
		500.f, 50.f);
	Label* play = new Label("Jugar", sf::Color::Black, font, sf::Text::Bold, 100,
		500.f, 250.f);
	Label* about = new Label("Acerca", sf::Color::Black, font, sf::Text::Bold,
		100, 500.f, 450.f);

	titleWindow.draw(titleSprite);
	titleWindow.draw(title->getTextInstance());
	titleWindow.draw(play->getTextInstance());
	titleWindow.draw(about->getTextInstance());
	titleWindow.display();

	while (titleWindow.isOpen()) {

		while (titleWindow.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				titleWindow.close();
				break;

			case sf::Event::MouseButtonPressed:
				if (isMouseButtonPressedLeft()) {
					if (isClicked(play->get_pos_x(), play->get_pos_x() + 300,
						play->get_pos_y(), play->get_pos_y() + 100)) {
						actualWindow->close();
						goPlayView();
					}
					if (isClicked(about->get_pos_x(), about->get_pos_x() + 300,
						about->get_pos_y(), about->get_pos_y() + 100)) {
						actualWindow->close();
						goAboutView();
					}
				}
				break;

			default:
				if (isEscapePressed())
					titleWindow.close();
				break;
			}
		}
	}
}

bool Window::isMouseButtonPressedLeft() {
	if (event.mouseButton.button == sf::Mouse::Left)
		return true;
	return false;
}

bool Window::isClicked(int x0, int x1, int y0, int y1) {
	if (event.mouseButton.x > x0 && event.mouseButton.y > y0 &&
		event.mouseButton.x < x1 && event.mouseButton.y < y1)
		return true;
	return false;
}

void Window::goAboutView() {
	sf::Font font;
	sf::RenderWindow aboutWindow(sf::VideoMode(1280, 720), "About");
	this->actualWindow = &aboutWindow;
	sf::Texture aboutImage;
	aboutImage.loadFromFile("Images/acercaDe.jpg");
	sf::Sprite aboutSprite(aboutImage);
	font.loadFromFile("mononoki.ttf");
	Label* back =
		new Label("<---", sf::Color::Black, font, sf::Text::Bold, 18, 20.f, 20.f);

	aboutWindow.draw(aboutSprite);
	aboutWindow.draw(back->getTextInstance());
	aboutWindow.display();

	while (aboutWindow.isOpen()) {
		while (aboutWindow.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				aboutWindow.close();
				break;

			case sf::Event::MouseButtonPressed:
				if (isMouseButtonPressedLeft()) {
					showCoordinates(aboutWindow);
					if (isClicked(back->get_pos_x(), back->get_pos_x() + 50,
						back->get_pos_y(), back->get_pos_y() + 25)) {
						actualWindow->close();
						goTitleView();
					}
				}
				break;

			default:
				break;
			}
		}
	}
}

void Window::goPlayView() {
	sf::RenderWindow playWindow(sf::VideoMode(1280, 720), "Play");
	this->actualWindow = &playWindow;
	sf::Texture playImage;
	playImage.loadFromFile("Images/catan_1280x720.jpg");
	sf::Sprite playSprite(playImage);
	playWindow.draw(playSprite);
	sf::Font arial;

	printBoard(playWindow);
	printMaterialCard(playWindow);
	printTown(playWindow);

	Button btn1("ClickMe", { 200, 50 }, 20, sf::Color::Green, sf::Color::Black);
	btn1.setPosition({ 800, 200 });
	btn1.setFont(arial);
	btn1.drawTo(playWindow);
	playWindow.display();

	while (playWindow.isOpen()) {
		while (playWindow.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				playWindow.close();
				break;

			case sf::Event::KeyPressed:
				if (isEscapePressed()) {
					goTitleView();
					playWindow.close();
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (isMouseButtonPressedLeft())
					showCoordinates(playWindow);
				break;

			default:
				break;
			}
		}
	}
}

bool Window::isEscapePressed() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return true;
	return false;
}

void Window::showCoordinates(sf::RenderWindow& window) {
	std::cout << "x: " << sf::Mouse::getPosition(window).x << std::endl;
	std::cout << "y: " << sf::Mouse::getPosition(window).y << std::endl;
}

void Window::printResources(sf::RenderWindow& window, std::string url, int x,
	int y) {
	std::string img = url;
	sf::Texture path;
	path.loadFromFile(img);
	sf::Sprite pathSprite(path);
	pathSprite.setPosition(static_cast<float>(x), static_cast<float>(y));
	window.draw(pathSprite);
}

void Window::printBoard(sf::RenderWindow& window) {
	int top_height = 10; // primera,segunda,tercera
	int bot_height = 10; // ultima y penultima columna de hexagonos
	int cycle_cord_x = 0;

	DataStructures dataStructures;
	dataStructures.loadLands();
	Node<Land>* temp = dataStructures.lands.head;
	std::cout << temp->getData().getUrl();

	bot_height += 295;
	for (cycle_cord_x = 470; cycle_cord_x <= 620; cycle_cord_x += 75) {
		std::string tempUrl = temp->getData().getUrl();
		Window::getInstance().printResources(window, tempUrl, cycle_cord_x,
			top_height);
		temp = temp->getNext();
		tempUrl = temp->getData().getUrl();

		Window::getInstance().printResources(window, tempUrl, cycle_cord_x,
			bot_height);
		temp = temp->getNext();
	}

	top_height += 75;
	bot_height = 230;
	for (cycle_cord_x = 435; cycle_cord_x <= 695; cycle_cord_x += 75) {
		std::string tempUrl = temp->getData().getUrl();
		Window::getInstance().printResources(window, tempUrl, cycle_cord_x,
			top_height);
		temp = temp->getNext();
		tempUrl = temp->getData().getUrl();

		Window::getInstance().printResources(window, tempUrl, cycle_cord_x,
			bot_height);
		temp = temp->getNext();
	}

	top_height += 75;
	for (cycle_cord_x = 400; cycle_cord_x <= 700; cycle_cord_x += 75) {
		std::string tempUrl = temp->getData().getUrl();

		Window::getInstance().printResources(window, tempUrl, cycle_cord_x,
			top_height);
		temp = temp->getNext();
	}
}

void Window::printMaterialCard(sf::RenderWindow& window) {
	printResources(window, "Images/resourcesCards/clayCard.png", 0, 240);
	printResources(window, "Images/resourcesCards/mineralCard.png", 70, 240);
	printResources(window, "Images/resourcesCards/wheatCard.png", 140, 240);
	printResources(window, "Images/resourcesCards/woodCard.png", 210, 240);
	printResources(window, "Images/resourcesCards/woolCard.png", 280, 240);
	printResources(window, "Images/extraCards/progressCardBackwards.png", 0, 370);
	printResources(window, "Images/extraCards/pricingTable.jpeg", 0, 20);
}

void Window::printTown(sf::RenderWindow& window) {
	int top_height = 5; // primera,segunda,tercera
	int bot_height = 5; // ultima y penultima columna de hexagonos
	int cycle_cord_x = 0;
	int i = 1;
	DataStructures dataStructures;
	dataStructures.makeGraph();
	Vertex* temp = dataStructures.graph.firstVertex;

	// Cambiar -> mapa de Rutas
	std::string tempUrl = "Images/puebloX.png";

	bot_height += 295;
	for (cycle_cord_x = 500; cycle_cord_x <= 650; cycle_cord_x += 75) {

		Window::getInstance().printResources(window, tempUrl, cycle_cord_x,
			top_height);
		temp->town->setPosX(cycle_cord_x);
		temp->town->setPosY(top_height);
		temp = temp->next;

		Window::getInstance().printResources(window, tempUrl, cycle_cord_x,
			bot_height);
		temp->town->setPosX(cycle_cord_x);
		temp->town->setPosY(top_height);
		temp = temp->next;
	}

	top_height += 75;
	bot_height = 235;
	for (cycle_cord_x = 465; cycle_cord_x <= 690; cycle_cord_x += 75) {

		Window::getInstance().printResources(window, tempUrl, cycle_cord_x,
			top_height);
		temp->town->setPosX(cycle_cord_x);
		temp->town->setPosY(top_height);
		temp = temp->next;
		Window::getInstance().printResources(window, tempUrl, cycle_cord_x,
			bot_height);
		temp->town->setPosX(cycle_cord_x);
		temp->town->setPosY(top_height);
		temp = temp->next;
	}

	top_height += 75;
	for (cycle_cord_x = 430; cycle_cord_x <= 655; cycle_cord_x += 75) {
		Window::getInstance().printResources(window, tempUrl, cycle_cord_x,
			top_height);
		temp->town->setPosX(cycle_cord_x);
		temp->town->setPosY(top_height);
		temp = temp->next;
	}
	dataStructures.printVertexXY();
}