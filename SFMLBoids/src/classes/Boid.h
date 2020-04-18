#pragma once
#include <SFML/Graphics.hpp>
//aggregation?

class Boid
{
public:
	Boid();
	void update();
private:
	float x;
	float y;

	const float magnitude;
	float direction; //degrees, where 0 degrees is pointing to the left
};

