#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {
	end();
}

void Scene::start() {
	while (ui.getRenderWindow().isOpen()) {
		ui.pollEvent();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (click == false) { //this bool/if statement is to make sure it only runs once
				click = true;
				boids.addBoid(sf::Mouse::getPosition(ui.getRenderWindow()).x, sf::Mouse::getPosition(ui.getRenderWindow()).y);
			}
		} else {
			click = false;
		}

		boids.update();
		ui.getRenderWindow().clear();
		ui.draw();
		boids.draw(ui.getRenderWindow());
		ui.getRenderWindow().display();
	}
}

void Scene::end() {

}