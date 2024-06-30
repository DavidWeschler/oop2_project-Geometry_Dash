#pragma once

#include "GameObj/MovablesObj/Enemy.h"
#include "Animations/Animation.h"

class Robot : public Enemy
{
public:
	Robot(World& world, sf::Color color, sf::Vector2f pos);
	virtual void move(sf::Time time);
	virtual ~Robot() = default;
	void setDir();

private:
	static bool m_registerItRobot;
	TexturesManger& m_resources = TexturesManger::instance();
	Direction m_dir = Direction::Left;
	Animation m_animation;
	sf::Clock m_aiTime;
	int m_way;
};