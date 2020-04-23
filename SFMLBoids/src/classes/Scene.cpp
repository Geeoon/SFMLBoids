#include "Scene.h"

Scene::Scene() {
	start();
}

Scene::~Scene() {
	end();
}

void Scene::start() {
	while (ui.getRenderWindow().isOpen()) {
		ui.pollEvent();

		boids.update();
		ui.getRenderWindow().clear();
		ui.draw();
		boids.draw(ui.getRenderWindow());
		ui.getRenderWindow().display();
	}
}

void Scene::end() {

}