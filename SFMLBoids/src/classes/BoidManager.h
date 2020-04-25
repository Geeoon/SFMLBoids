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
private:
	sf::Clock clock;
	sf::Time elapsedTime;
	std::vector<Boid> boids;
	const int cols = 5;
	const int rows = 5;
};

