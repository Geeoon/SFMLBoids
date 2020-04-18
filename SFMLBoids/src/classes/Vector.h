#pragma once
#include <cmath>
#define M_PI   3.14159265358979323846264338327950288

class Vector
{
public:
	Vector(float dir, float mag);
	float getXComponent();
	float getYComponent();
	float getMagnitude();
	float getDirectionDeg();
	float getDirectionRad();
	Vector addTo(Vector vector2);
private:
	float direction;
	float magnitude;
};
