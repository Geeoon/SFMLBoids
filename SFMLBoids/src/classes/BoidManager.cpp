#include "BoidManager.h"

BoidManager::BoidManager() {
	boids.resize(cols * rows);
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			boids[i * rows + j].setX(20 * j);
			boids[i * rows + j].setY(20 * i);
		}
	}
}

void BoidManager::update() {
	elapsedTime = clock.getElapsedTime();
	clock.restart();
	for (int i = 0; i < cols * rows; i++) {
		boids[i].update(boids, elapsedTime.asSeconds());
	}
}

void BoidManager::draw(sf::RenderWindow& window) {
	for (int i = 0; i < cols * rows; i++) {
		//not technically drawing, but it has the window passed, so im just gonna use it
		boids[i].teleportEdge(window);
		//actually drawing
		window.draw(boids[i].getSprite());
	}
}