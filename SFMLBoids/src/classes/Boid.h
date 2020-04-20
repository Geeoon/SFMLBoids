#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
//aggregation?

class Boid
{
public:
	Boid();
	void update();
	sf::CircleShape getSprite();
private:
	sf::CircleShape triangle; //says cirlceshape but it gets modified in the constructor to be a triangle
	float x;
	float y;
	Vector velocity;
};

