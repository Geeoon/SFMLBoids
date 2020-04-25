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
	void teleportEdge(sf::RenderWindow& window);
	sf::CircleShape getSprite();
private:
	sf::CircleShape triangle; //says cirlceshape but it gets modified in the constructor to be a triangle
	Vector separation(std::vector<Boid>& boids);
	Vector alignment(std::vector<Boid>& boids);
	Vector cohesion(std::vector<Boid>& boids);
	Vector avoidEdge(std::vector<Boid>& boids);
	
	void capSpeed();
	double x;
	double y;
	Vector velocity;

	const double seperationFactor = 10; //10
	const double cohesionFactor = 1000; //0.5; cohesion causes jittering nad forces the boids to go up and to the left
	const double alignmentFactor = 0.00002; //0.00002
	const double acceleration = 5;
	const double seperationRadius = 20;
	const double adhesionRadius = 100;
	const double alignmentRadius = 50;

};

