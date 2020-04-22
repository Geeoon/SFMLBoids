#include "BoidManager.h"

BoidManager::BoidManager() {

	boids.resize(numBoids);
	for (int i = 0; i < numBoids; i++) {
		boids[i].setX(300 + 20*i);
		boids[i].setY(300);
	}
}

void BoidManager::update() {
	elapsedTime = clock.getElapsedTime();
	clock.restart();
	for (int i = 0; i < numBoids; i++) {
		boids[i].update(boids, elapsedTime.asSeconds());
	}
}

void BoidManager::draw(sf::RenderWindow& window) {
	for (int i = 0; i < numBoids; i++) {
		window.draw(boids[i].getSprite());
	}
}