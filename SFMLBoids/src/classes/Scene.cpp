#include "Scene.h"

Scene::Scene() {
	
}

Scene::~Scene() {
	end();
}

void Scene::start() {
	while (ui.getRenderWindow().isOpen()) {
		ui.getRenderWindow().clear();

		ui.getRenderWindow().display();
	}
}

void Scene::end() {

}