#include "Vector.h"

Vector::Vector() {
	direction = 0;
	magnitude = 0;
}

Vector::Vector(float dir, float mag) {
	direction = dir;
	magnitude = mag;
}

void Vector::setDirection(float dir) {
	direction = dir;
}

void Vector::setMagnitude(float mag) {
	magnitude = mag;
}

float Vector::getXComponent() {
	return magnitude * sin(getDirectionRad());
}

float Vector::getYComponent() {
	return magnitude * cos(getDirectionRad());
}

float Vector::getMagnitude() {
	return magnitude;
}

float Vector::getDirectionDeg() {
	return direction;
}

float Vector::getDirectionRad() {
	return direction * M_PI / 180;
}

Vector Vector::addTo(Vector vector2) {
	float newX = vector2.getXComponent() + getXComponent();
	float newY = vector2.getYComponent() + getYComponent();
	float newMagnitude = sqrt((newX * newX) + (newY * newY));
	float newDirection = atan2f(newY, newX);
	return Vector(newDirection, newMagnitude);
}