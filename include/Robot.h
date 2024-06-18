#pragma once

#include "Enemy.h"

class Robot : public Enemy
{
public:
	Robot(std::unique_ptr<b2World>& world, sf::Vector2f position);
	virtual void makeVirtural() {};
private:
	static bool m_registeritRobot;
};