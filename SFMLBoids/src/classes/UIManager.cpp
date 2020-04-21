#include "UIManager.h"

UIManager::UIManager() {
	window.create(sf::VideoMode(850, 850), "Boids");
	window.setFramerateLimit(200);
}

sf::RenderWindow& UIManager::getRenderWindow() {
	return window;
}

void UIManager::pollEvent() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Resized)
		{
			sf::FloatRect visibleArea(0, 0, (signed int)event.size.width, (signed int)event.size.height);
			window.setView(sf::View(visibleArea));
		}
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void UIManager::draw() {

}