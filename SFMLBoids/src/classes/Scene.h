#pragma once
#include <SFML/Graphics.hpp>
#include "UIManager.h"
#include "BoidManager.h"


class Scene
{
public:
	Scene();
	~Scene();
	void start();
	void end();
private:
	UIManager ui;
	BoidManager boids;
};

