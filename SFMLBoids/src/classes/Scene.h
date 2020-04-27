#pragma once
#include <SFML/Graphics.hpp>
#include "UIManager.h"
#include "BoidManager.h"
#include <iostream>

class Scene
{
public:
	Scene();
	~Scene();
	void start();
	void end();
	void input();
private:
	UIManager ui;
	std::unique_ptr<BoidManager> boids;
	bool click = false;
	double scale = 1;
};

