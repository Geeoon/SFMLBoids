#pragma once
#include "UIManager.h"
#include "BoidManager.h"
#include <SFML/Graphics.hpp>

class Scene
{
public:

private:
	sf::RenderWindow window;
	UIManager ui;
	BoidManager boids;
};

