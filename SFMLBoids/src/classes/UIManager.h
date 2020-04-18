#pragma once
#include <SFML/Graphics.hpp>

class UIManager
{
public:
	UIManager();
	sf::RenderWindow& getRenderWindow();
private:
	sf::RenderWindow window;
	void draw();
	void pollEvent();
};

