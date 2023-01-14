#include "Window.hpp"


void Window::goTitleView() {
	sf::RenderWindow titleWindow(sf::VideoMode(1280, 720), "Main Menu");
	sf::Texture titleImage;
	titleImage.loadFromFile("Images/inicio.jpg");
	sf::Sprite titleSprite(titleImage);
	font.loadFromFile("mononoki.ttf");
	Label* title = new Label("Catan", sf::Color::Black, font, sf::Text::Bold, 100, 500.f, 50.f);
	Label* play = new Label("Jugar", sf::Color::Black, font, sf::Text::Bold, 100, 500.f, 250.f);
	Label* about = new Label("Acerca", sf::Color::Black, font, sf::Text::Bold, 100, 500.f, 450.f);

	while (titleWindow.isOpen()) {

		while (titleWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				titleWindow.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					titleWindow.close();
					goAboutView();
				}

			}
		}
		titleWindow.draw(titleSprite);
		titleWindow.draw(title->getTextInstance());
		titleWindow.draw(play->getTextInstance());
		titleWindow.draw(about->getTextInstance());
		titleWindow.display();
	}
}

void Window::showCoordinates(sf::RenderWindow& window) {
	std::cout << "x: " << sf::Mouse::getPosition(window).x << std::endl;
	std::cout << "y: " << sf::Mouse::getPosition(window).y << std::endl;
}

bool Window::isMouseOverAbout() {
	return false;
}

void Window::goAboutView() {
	sf::RenderWindow aboutWindow(sf::VideoMode(1280, 720), "About");
	sf::Texture aboutImage;
		aboutImage.loadFromFile("Images/acercaDe.jpg");
	sf::Sprite aboutSprite(aboutImage);
	while (aboutWindow.isOpen()) {
		while (aboutWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				aboutWindow.close();
		}
		aboutWindow.draw(aboutSprite);
		aboutWindow.display();
	}
}

void Window::printHexagon(std::string url, int x, int y) {
	/*const char* const img = url.c_str();
	CImg<unsigned char> imageHexa(img);
	image2.draw_image(x, y, imageHexa);*/
}
void Window::printImageTown(std::string url, int x, int y) {
	/*const char* const img = url.c_str();
	CImg<unsigned char> imageTown(img);
	image2.draw_image(x, y, imageTown);*/
}

void Window::printBoard() {
	/*int top_height = 10; // primera,segunda,tercera
	int bot_height = 10; // ultima y penultima columna de hexagonos
	int cycle_cord_x = 0;

	DataStructures dataStructures;
	dataStructures.loadLands();
	Node<Land>* temp = dataStructures.lands.head;
	std::cout << temp->getData().getUrl();

	bot_height += 295;
	for (cycle_cord_x = 470; cycle_cord_x <= 620; cycle_cord_x += 75) {
			std::string tempUrl = temp->getData().getUrl();

			Window::getInstance().printHexagon(tempUrl, cycle_cord_x, top_height);
			temp = temp->getNext();
			tempUrl = temp->getData().getUrl();

			Window::getInstance().printHexagon(tempUrl, cycle_cord_x, bot_height);
			temp = temp->getNext();
	}

	top_height += 75;
	bot_height = 230;
	for (cycle_cord_x = 435; cycle_cord_x <= 695; cycle_cord_x += 75) {
			std::string tempUrl = temp->getData().getUrl();
			Window::getInstance().printHexagon(tempUrl, cycle_cord_x, top_height);
			temp = temp->getNext();
			tempUrl = temp->getData().getUrl();

			Window::getInstance().printHexagon(tempUrl, cycle_cord_x, bot_height);
			temp = temp->getNext();
	}

	top_height += 75;
	for (cycle_cord_x = 400; cycle_cord_x <= 700; cycle_cord_x += 75) {
			std::string tempUrl = temp->getData().getUrl();

			Window::getInstance().printHexagon(tempUrl, cycle_cord_x, top_height);
			temp = temp->getNext();
	}*/
}

void Window::printMaterialCard() {
	///////MATERIAL CARD IMAGE/////////
	/*CImg<unsigned char> image_clay("Images/resourcesCards/clayCard.png");
	CImg<unsigned char> image_mineral("Images/resourcesCards/mineralCard.png");
	CImg<unsigned char> image_wheat("Images/resourcesCards/wheatCard.png");
	CImg<unsigned char> image_wood("Images/resourcesCards/woodCard.png");
	CImg<unsigned char> image_wool("Images/resourcesCards/woolCard.png");
	CImg<unsigned char> image_develop(
			"Images/extraCards/progressCardBackwards.png");

	image2.draw_image(0, 240, image_clay);
	image2.draw_image(70, 240, image_mineral);
	image2.draw_image(140, 240, image_wheat);
	image2.draw_image(210, 240, image_wood);
	image2.draw_image(280, 240, image_wool);
	image2.draw_image(0, 370, image_develop);*/
}
void Window::Image(std::string url) {}

void Window::printTown() {
	/*int top_height = 5; // primera,segunda,tercera
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

			Window::getInstance().printImageTown(tempUrl, cycle_cord_x,
	top_height); temp->town->setPosX(cycle_cord_x);
			temp->town->setPosY(top_height);
			temp = temp->next;

			Window::getInstance().printImageTown(tempUrl, cycle_cord_x,
	bot_height); temp->town->setPosX(cycle_cord_x);
			temp->town->setPosY(top_height);
			temp = temp->next;
	}

	top_height += 75;
	bot_height = 235;
	for (cycle_cord_x = 465; cycle_cord_x <= 690; cycle_cord_x += 75) {

			Window::getInstance().printImageTown(tempUrl, cycle_cord_x,
	top_height); temp->town->setPosX(cycle_cord_x);
			temp->town->setPosY(top_height);
			temp = temp->next;
			Window::getInstance().printImageTown(tempUrl, cycle_cord_x,
	bot_height); temp->town->setPosX(cycle_cord_x);
			temp->town->setPosY(top_height);
			temp = temp->next;
	}

	top_height += 75;
	for (cycle_cord_x = 430; cycle_cord_x <= 655; cycle_cord_x += 75) {
			Window::getInstance().printImageTown(tempUrl, cycle_cord_x,
	top_height); temp->town->setPosX(cycle_cord_x);
			temp->town->setPosY(top_height);
			temp = temp->next;
	}
	dataStructures.printVertexXY();*/
}