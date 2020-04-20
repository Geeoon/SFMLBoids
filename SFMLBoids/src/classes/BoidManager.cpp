#include "BoidManager.h"

BoidManager::BoidManager() {
	boids.resize(numBoids);
}

void BoidManager::update() {
	for (int i = 0; i < numBoids; i++) {
		boids[i].update();
	}
}

void BoidManager::draw(sf::RenderWindow& window) {
	for (int i = 0; i < numBoids; i++) {
		window.draw(boids[i].getSprite());
	}
}