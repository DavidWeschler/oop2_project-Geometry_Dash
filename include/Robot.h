#pragma once

#include "Enemy.h"
#include <SFML/Graphics.hpp>//maybe go
#include "Animation.h"

class Robot : public Enemy
{
public:
	Robot(std::unique_ptr<b2World>& world, sf::Vector2f position);
	virtual void makeVirtural() {};
	virtual void move(sf::Time time);
	virtual ~Robot() = default;

private:
	static bool m_registeritRobot;
	Singleton& m_resources = Singleton::instance();

	//sf::RectangleShape* m_robot;
	Direction m_dir = Direction::Left;
	Animation m_animation;
	sf::Clock m_aiTime;
};