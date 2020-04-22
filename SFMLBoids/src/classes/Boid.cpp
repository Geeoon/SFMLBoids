#include "Boid.h"

Boid::Boid() {
	x = 300;
	y = 300;
	velocity.setDirection(0);
	velocity.setMagnitude(0);
	triangle.setPointCount(3); //triangle
	triangle.setRadius(5);
	triangle.setFillColor(sf::Color::Black);
	triangle.setOrigin(triangle.getRadius(), triangle.getRadius());
	triangle.setOutlineColor(sf::Color(0, 255, 65));
	triangle.setOutlineThickness(2);
}

Vector Boid::separation(std::vector<Boid>& boids) {
	//separation
	Vector seperation;
	for (int i = 0; i < boids.size(); i++) { //it jitters becasue I have no clue
		if (&boids[i] != this) {
			double xDist = x - boids[i].getX();
			double yDist = y - boids[i].getY();
			double dist = sqrt((xDist * xDist) + (yDist * yDist));
			double angle = atan2f(yDist, xDist);
			angle = angle * (double)(180 / M_PI); //convert from radians to degrees
			
			if (dist <= 50) {
				seperation.addTo(Vector(angle, 5 / dist));
			}
		}
	}
	
	return seperation;
}

void Boid::update(std::vector<Boid>& boids, double time) {
	/*
	//cohesion
	for (int i = 0; i < boids.size(); i++) {
		float xDist = boids[i].getX() - x;
		float yDist = y - boids[i].getY();
		float dist = sqrt((x * x) + (y * y));
		if (dist <= 30) {

		}
	}

	float avrgDir = 0;
	//steering
	for (int i = 0; i < boids.size(); i++) {
		float xDist = boids[i].getX() - x;
		float yDist = y - boids[i].getY();
		float dist = sqrt((x * x) + (y * y));
		if (dist <= 30) {
			avrgDir += boids[i].getVelocity().getDirectionDeg();
		}
	}
	avrgDir /= boids.size();
	*/
	velocity.addTo(separation(boids));

	x += velocity.getXComponent() * time;
	y -= velocity.getYComponent() * time;
	triangle.setPosition(x, y);
	triangle.setRotation(velocity.getDirectionDeg());
	std::cout << velocity.getDirectionDeg() << std::endl;
}

Vector Boid::getVelocity() {
	return velocity;
}

double Boid::getX() {
	return x;
}

double Boid::getY() {
	return y;
}

void Boid::setX(double newX) {
	x = newX;
}

void Boid::setY(double newY) {
	y = newY;
}

sf::CircleShape Boid::getSprite() {
	return triangle;
}