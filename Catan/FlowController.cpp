#include "FlowController.hpp"

void FlowController::initializeFlow() {
	Window::getInstance().goTitleView();
}

void FlowController::goView(sf::RenderWindow window) {
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.display();
	}
}

void FlowController::close() {}