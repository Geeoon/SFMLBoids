#include "Scene.h"

Scene::Scene() {
	Vector vect1(360, 2);
	Vector vect2(360+90, 3);
	std::cout << "Magnitude " << vect1.add(vect2).getMagnitude() << std::endl;
	std::cout << "Angle " << vect1.add(vect2).getDirectionDeg() << std::endl;
	std::cout << "dX " << vect1.add(vect2).getXComponent() << std::endl;
	std::cout << "dY " << vect1.add(vect2).getYComponent() << std::endl;
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