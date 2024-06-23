#pragma once

#include "GameObj/MovablesObj/Enemy.h"
#include <SFML/Graphics.hpp>//maybe go
#include "Animations/Animation.h"

class Robot : public Enemy
{
public:
	Robot(std::unique_ptr<b2World>& world, sf::Vector2f position);
	virtual void makeVirtural() {};
	virtual void move(sf::Time time);
	virtual ~Robot() = default;
	void setDir();

private:
	static bool m_registeritRobot;
	Singleton& m_resources = Singleton::instance();
	Direction m_dir = Direction::Left;
	Animation m_animation;
	sf::Clock m_aiTime;
	int m_way;
};