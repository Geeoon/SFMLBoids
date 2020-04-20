#pragma once
#include <SFML/Graphics.hpp>

class UIManager
{
public:
	UIManager();
	sf::RenderWindow& getRenderWindow();
	void pollEvent();
	void draw();
private:
	sf::RenderWindow window;
};

