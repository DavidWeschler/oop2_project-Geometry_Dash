#pragma once

#include "Movable.h"
#include "Singleton.h"

class Player : public Movable
{
public:
	Player();
	Player(sf::Texture& texture, sf::Color color, sf::Vector2f pos);
	void setChosenPlayer(int i);
	void setLocation(sf::Vector2f pos);
private:

	Singleton& m_resources = Singleton::instance();
	int m_bullets;
};





