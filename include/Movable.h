#pragma once

#include "Object.h"

class Movable : public Object
{
public:
	Movable(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f pos)
		: Object(world, color, pos, b2_dynamicBody) {};
	virtual void makeVirtural() = 0;
	virtual ~Movable() = default;
	//virtual void move() = 0;
};