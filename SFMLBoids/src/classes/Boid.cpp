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
	Vector seperation(0, 0);
	for (int i = 0; i < boids.size(); i++) { //it jitters becasue I have no clue
		if (&boids[i] != this) {
			double xDist = x - boids[i].getX();
			double yDist = y - boids[i].getY();
			double dist = sqrt((xDist * xDist) + (yDist * yDist));

			
			if (dist <= 30) {
				double angle = 0;
				if (yDist == 0 && xDist > 0) {
					angle = 0;
				} else if (yDist > 0 && xDist == 0) {
					angle = 90;
				} else if (yDist == 0 && xDist < 0) {
					angle = 180;
				} else if (yDist < 0 && xDist == 0) {
					angle = 270;
				} else if (yDist > 0 && xDist > 0) {//first quad
					angle = atan(yDist / xDist) * 180 / M_PI;
				} else if (yDist > 0 && xDist < 0) {//second quad
					angle = 180 + (atan(yDist / xDist) * 180 / M_PI);
				} else if (yDist < 0 && xDist < 0) {//third quad
					angle = 270 - (atan(yDist / xDist) * 180 / M_PI);
				} else if (yDist < 0 && xDist > 0) {//fourth quad
					angle = 360 + (atan(yDist / xDist) * 180 / M_PI);
				}

				seperation.addTo(Vector(angle, 20 / (dist * dist)));
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
	y += velocity.getYComponent() * time;
	triangle.setPosition(x, y);
	triangle.setRotation(velocity.getDirectionDeg());
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