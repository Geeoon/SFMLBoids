#include "Scene.h"

Scene::Scene() {
	input();
	boids.reset(new BoidManager(scale));
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
				boids->addBoid(sf::Mouse::getPosition(ui.getRenderWindow()).x, sf::Mouse::getPosition(ui.getRenderWindow()).y);
			}
		} else {
			click = false;
		}

		boids->update();
		ui.getRenderWindow().clear();
		ui.draw();
		boids->draw(ui.getRenderWindow());
		ui.getRenderWindow().display();
	}
}

void Scene::end() {

}

void Scene::input() {
	std::cout << "Enter scale for boids (if you are unsure, use 1): ";
	if (scale <= 0) {
		std::cout << "The scale must be larger than 0." << std::endl;
		input();
	} else {
		std::cin >> scale;
	}
}