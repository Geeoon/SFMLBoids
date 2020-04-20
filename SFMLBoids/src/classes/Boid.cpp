#include "Boid.h"

Boid::Boid() {
	x = 0;
	y = 0;
	velocity.setDirection(90);
	velocity.setMagnitude(0.1);
	triangle.setPointCount(3); //triangle
	triangle.setRadius(10);
	triangle.setFillColor(sf::Color::Black);
	triangle.setOrigin(triangle.getRadius(), triangle.getRadius());
	triangle.setOutlineColor(sf::Color(0, 255, 65));
	triangle.setOutlineThickness(3);
}

void Boid::update() {
	x += velocity.getXComponent();
	y += velocity.getYComponent();
	std::cout << velocity.getYComponent() << std::endl;
	triangle.setPosition(x, y);
}

sf::CircleShape Boid::getSprite() {
	return triangle;
}