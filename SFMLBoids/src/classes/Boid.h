#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#define M_PI   3.14159265358979323846264338327950288

class Boid
{
public:
	Boid();
	void update(std::vector<Boid>& boids, double time);
	Vector getVelocity();
	double getX();
	double getY();
	void setX(double newX);
	void setY(double newY);
	sf::CircleShape getSprite();
private:
	sf::CircleShape triangle; //says cirlceshape but it gets modified in the constructor to be a triangle
	Vector separation(std::vector<Boid>& boids);
	Vector alignment(std::vector<Boid>& boids);
	Vector cohesion(std::vector<Boid>& boids);
	double x;
	double y;
	Vector velocity;
};

