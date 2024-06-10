#pragma once

#include "Object.h"

class Movable : public Object
{
public:
	Movable(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f pos)
		: Object(world, texture, color, pos) {};
	virtual void makeVirtural() = 0;
	virtual ~Movable() = default;

};