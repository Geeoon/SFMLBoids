#include "UIManager.h"

UIManager::UIManager() {
	window.create(sf::VideoMode(850, 850), "SFML window");
	window.setFramerateLimit(200);
}

sf::RenderWindow& UIManager::getRenderWindow() {
	return window;
}