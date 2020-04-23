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

double Vector::getYComponent() {
	return magnitude * sin(getDirectionRad());
}

double Vector::getXComponent() {
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
	double newDirection = 0;

	if (newY == 0 && newX > 0) {
		newDirection = 0;
	} else if (newY > 0 && newX == 0) {
		newDirection = 90;
	} else if (newY == 0 && newX < 0) {
		newDirection = 180;
	} else if (newY < 0 && newX == 0) {
		newDirection = 270;
	} else if (newY > 0 && newX > 0) {//first quad
		newDirection = atan(newY / newX) * 180 / M_PI;
	} else if (newY > 0 && newX < 0) {//second quad
		newDirection = 180 + (atan(newY / newX) * 180 / M_PI);
	} else if (newY < 0 && newX < 0) {//third quad
		newDirection = 270 - (atan(newY / newX) * 180 / M_PI);
	} else if (newY < 0 && newX > 0) {//fourth quad
		newDirection = 360 + (atan(newY / newX) * 180 / M_PI);
	}

	direction = newDirection;
	magnitude = newMagnitude;
}

Vector Vector::add(Vector vector2) {
	double newX = vector2.getXComponent() + getXComponent();
	double newY = vector2.getYComponent() + getYComponent();
	double newMagnitude = sqrt((newX * newX) + (newY * newY));
	double newDirection = 0;

	if (newY == 0 && newX > 0) {
		newDirection = 0;
	} else if (newY > 0 && newX == 0) {
		newDirection = 90;
	} else if (newY == 0 && newX < 0) {
		newDirection = 180;
	} else if (newY < 0 && newX == 0) {
		newDirection = 270;
	} else if (newY > 0 && newX > 0) {//first quad
		newDirection = atan(newY / newX) * 180 / M_PI;
	} else if (newY > 0 && newX < 0) {//second quad
		newDirection = 180 + (atan(newY / newX) * 180 / M_PI);
	} else if (newY < 0 && newX < 0) {//third quad
		newDirection = 270 - (atan(newY / newX) * 180 / M_PI);
	} else if (newY < 0 && newX > 0) {//fourth quad
		newDirection = 360 + (atan(newY / newX) * 180 / M_PI);
	}
	return Vector(newDirection, newMagnitude);
}