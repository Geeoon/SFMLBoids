#pragma once
#include <cmath>
#include <iostream>
#define M_PI   3.14159265358979323846264338327950288

class Vector
{
public:
	Vector();
	Vector(double dir, double mag);
	void setDirection(double dir); //direction 0 is strait down
	void setMagnitude(double mag);
	double getXComponent();
	double getYComponent();
	double getMagnitude();
	double getDirectionDeg();
	double getDirectionRad();
	void addTo(Vector vector2);
	Vector add(Vector vector2);
private:
	double direction;
	double magnitude;
};

