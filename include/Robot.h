#pragma once

#include "Enemy.h"
#include <SFML/Graphics.hpp>//maybe go

class Robot : public Enemy
{
public:
	Robot(std::unique_ptr<b2World>& world, sf::Vector2f position);
	virtual void makeVirtural() {};
	virtual void move(sf::Time time);
	virtual ~Robot() = default;
private:
	static bool m_registeritRobot;

	Animation m_animation;
	sf::Clock m_aiTime;
};