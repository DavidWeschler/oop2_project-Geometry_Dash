#pragma once

#include "Movable.h"

class Enemy : public Movable
{
public:
	Enemy(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, b2BodyType bodyType, sf::RectangleShape* enemy);
	virtual void makeVirtural() = 0;
	virtual void move(sf::Time time) = 0;
	virtual ~Enemy() = default;
};