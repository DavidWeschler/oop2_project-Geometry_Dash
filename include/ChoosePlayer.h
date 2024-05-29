#pragma once	

#include "SFML/Graphics.hpp"

class ChoosePlayer
{
public:
	ChoosePlayer();

	void go(sf::RenderWindow& window);
private:
	sf::RenderWindow* m_window;
};