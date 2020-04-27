#include "Boid.h"

Boid::Boid() {
	x = 300;
	y = 300;
	velocity.setDirection(0);
	velocity.setMagnitude(10);
	triangle.setPointCount(3); //triangle
	triangle.setRadius(5 * scale);
	triangle.setFillColor(sf::Color::Black);
	triangle.setOrigin(triangle.getRadius(), triangle.getRadius());
	triangle.setOutlineColor(sf::Color(0, 255, 65));
	triangle.setOutlineThickness(1);
	triangle.scale(1.0f, 1.25f);
}

Boid::Boid(double s) {
	scale = s;
	x = 300;
	y = 300;
	velocity.setDirection(0);
	velocity.setMagnitude(10);
	triangle.setPointCount(3); //triangle
	triangle.setRadius(5 * scale);
	triangle.setFillColor(sf::Color::Black);
	triangle.setOrigin(triangle.getRadius(), triangle.getRadius());
	triangle.setOutlineColor(sf::Color(0, 255, 65));
	triangle.setOutlineThickness(1);
	triangle.scale(1.0f, 1.25f);
}

Vector Boid::separation(std::vector<Boid>& boids) {
	//separation
	
	Vector seperation(0, 0);
	double finalX = 0;
	double finalY = 0;

	for (size_t i = 0; i < boids.size(); i++) {
		if (&boids[i] != this) {
			double xDist = x - boids[i].getX();
			double yDist = y - boids[i].getY();
			double dist = sqrt((xDist * xDist) + (yDist * yDist));

			
			if (dist <= seperationRadius * scale) {
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
					angle = 270 - (atan(xDist / yDist) * 180 / M_PI);
				} else if (yDist < 0 && xDist > 0) {//fourth quad
					angle = 360 + (atan(yDist / xDist) * 180 / M_PI);
				}
				seperation.addTo(Vector(angle, ((dist / seperationFactor) + (1/dist * 10) + 5) * scale));
			}
		}
	}
	return seperation;
}

Vector Boid::alignment(std::vector<Boid>& boids) {
	//alignment
	
	Vector alignment(0, 0);
	double averageAngle = 0;
	int count = 0;
	for (size_t i = 0; i < boids.size(); i++) {
		
		if (&boids[i] != this) {
			double xDist = x - boids[i].getX();
			double yDist = y - boids[i].getY();
			double dist = sqrt((xDist * xDist) + (yDist * yDist));

			if (dist <= alignmentRadius * scale) { //50
				count++;
				averageAngle += getVelocity().getDirectionDeg() - boids[i].getVelocity().getDirectionDeg();
			}
		}

	}
	if (count != 0) {
		averageAngle /= count;
	}

	if (averageAngle < 0) {
		alignment.addTo(Vector(getVelocity().getDirectionDeg() + 90, (averageAngle * alignmentFactor) * scale));
	} else if (averageAngle > 0) {
		alignment.addTo(Vector(getVelocity().getDirectionDeg() + 90, (averageAngle * alignmentFactor) * scale));
	}

	return alignment;
}

Vector Boid::cohesion(std::vector<Boid>& boids) {
	//cohesion
	Vector cohesion(0, 0);
	double avrgX = 0;
	double avrgY = 0;
	int count = 0;
	for (size_t i = 0; i < boids.size(); i++) {
		if (&boids[i] != this) {
			double xDist = boids[i].getX() - x;
			double yDist = boids[i].getY() - y;
			double dist = sqrt((xDist * xDist) + (yDist * yDist));



			if (dist <= cohesionRadius * scale) { //200
				count++;
				avrgX += xDist;
				avrgY += yDist;
			}
		}
	}

	if (count != 0) {
		avrgX /= count;
		avrgY /= count;
	}



	double xDist = avrgX;
	double yDist = avrgY;
	double dist = sqrt((xDist * xDist) + (yDist * yDist));

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
		angle = 270 - (atan(xDist / yDist) * 180 / M_PI);
	} else if (yDist < 0 && xDist > 0) {//fourth quad
		angle = 360 + (atan(yDist / xDist) * 180 / M_PI);
	}

	cohesion.addTo(Vector(angle, (dist / cohesionFactor) * scale));

	return cohesion;
}

Vector Boid::avoidEdge(sf::RenderWindow& window) {
	return Vector(0, 0);

}

void Boid::teleportEdge(sf::RenderWindow& window) {
	if (x > window.getSize().x) {
		x = 0;
	}

	if (x < 0) {
		x = window.getSize().x;
	}

	if (y > window.getSize().y) {
		y = 0;
	}

	if (y < 0) {
		y = window.getSize().y;
	}
}

Vector Boid::capSpeed() {
	Vector speedCap;
	if (velocity.getMagnitude() > maxSpeed * scale) {
		speedCap = Vector(velocity.getDirectionDeg(), ((maxSpeed * scale) - velocity.getMagnitude()) * scale);
	} else {
		speedCap = Vector(velocity.getDirectionDeg(), acceleration * scale);
	}
	return speedCap;
}

void Boid::update(std::vector<Boid>& boids, double time) {
	velocity.addTo(separation(boids));
	velocity.addTo(alignment(boids));
	velocity.addTo(cohesion(boids));
	velocity.addTo(capSpeed());
	x += velocity.getXComponent() * time;
	y += velocity.getYComponent() * time;
	triangle.setPosition((float)x, (float)y);
	triangle.setRotation((float)velocity.getDirectionDeg() + 90);
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

sf::CircleShape& Boid::getSprite() {
	return triangle;

}