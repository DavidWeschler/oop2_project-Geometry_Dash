#pragma once
#include "GameObj\MovablesObj\Movable.h"

class Enemy : public Movable
{
public:
	Enemy(World& world, sf::Vector2f position, sf::Vector2f boxSize);
	virtual void move(sf::Time time) = 0;
	virtual ~Enemy() = default;
};