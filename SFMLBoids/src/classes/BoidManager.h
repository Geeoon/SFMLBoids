#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Boid.h"

class BoidManager
{
public:
	BoidManager();
	BoidManager(double s);
	void update();
	void draw(sf::RenderWindow& window);
	void addBoid(double x, double y);
private:
	sf::Clock clock;
	sf::Time elapsedTime;
	std::vector<Boid> boids;
	const int cols = 10;
	const int rows = 10;
	double scale = 1;
};

