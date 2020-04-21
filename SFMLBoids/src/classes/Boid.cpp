#include "Boid.h"

Boid::Boid() {
	x = 300;
	y = 300;
	velocity.setDirection(45);
	velocity.setMagnitude(0.1f);
	triangle.setPointCount(3); //triangle
	triangle.setRadius(5);
	triangle.setFillColor(sf::Color::Black);
	triangle.setOrigin(triangle.getRadius(), triangle.getRadius());
	triangle.setOutlineColor(sf::Color(0, 255, 65));
	triangle.setOutlineThickness(2);
}

void Boid::update() {
	x += velocity.getXComponent();
	y -= velocity.getYComponent();
	std::cout << velocity.getYComponent() << std::endl;
	triangle.setPosition(x, y);
	triangle.setRotation(velocity.getDirectionDeg());
}

sf::CircleShape Boid::getSprite() {
	return triangle;
}