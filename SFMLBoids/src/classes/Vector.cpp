#include "Vector.h"

Vector::Vector() {
	direction = 0;
	magnitude = 0;
}

Vector::Vector(double dir, double mag) {
	direction = dir;
	magnitude = mag;
}

void Vector::setDirection(double dir) {
	direction = dir;
}

void Vector::setMagnitude(double mag) {
	magnitude = mag;
}

double Vector::getXComponent() {
	return magnitude * sin(getDirectionRad());
}

double Vector::getYComponent() {
	return magnitude * cos(getDirectionRad());
}

double Vector::getMagnitude() {
	return magnitude;
}

double Vector::getDirectionDeg() {
	return direction;
}

double Vector::getDirectionRad() {
	return direction * M_PI / 180;
}

void Vector::addTo(Vector vector2) {
	double newX = vector2.getXComponent() + getXComponent();
	double newY = vector2.getYComponent() + getYComponent();
	double newMagnitude = sqrt((newX * newX) + (newY * newY));
	double newDirection = atan2f(newY, newX);
	newDirection = newDirection * (double)(180 / M_PI) + 90;
	direction = newDirection;
	magnitude = newMagnitude;
}