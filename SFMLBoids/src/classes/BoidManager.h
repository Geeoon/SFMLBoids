#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Boid.h"

class BoidManager
{
public:
	BoidManager();
	void update();
	void draw(sf::RenderWindow& window);
	void addBoid(double x, double y);
private:
	sf::Clock clock;
	sf::Time elapsedTime;
	std::vector<Boid> boids;
	const int cols = 0;
	const int rows = 0;
};

