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
	sf::CircleShape& getSprite();
private:
	sf::CircleShape triangle; //says cirlceshape but it gets modified in the constructor to be a triangle
	Vector separation(std::vector<Boid>& boids);
	Vector alignment(std::vector<Boid>& boids);
	Vector cohesion(std::vector<Boid>& boids);
	Vector avoidEdge(sf::RenderWindow& window);
	Vector capSpeed();
	double x;
	double y;
	Vector velocity;

	/*issues I need to fix:
		boids like to overlap
	*/
	const double scale = .5;
	const double seperationFactor = 5; //5
	const double cohesionFactor = 15; //25
	const double alignmentFactor = 0.01; //0.01
	const double acceleration = 1;//1
	const double seperationRadius = 30;//25
	const double cohesionRadius = 200;//100
	const double alignmentRadius = 150;//50
	const double maxSpeed = 300;//300

};

