#pragma once

#include "Object.h"

class Static : public Object
{
public:
	Static(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, b2BodyType bodyType)
		: Object(world, color, position, bodyType) {};
	virtual void makeVirtural() = 0;
	virtual ~Static() =default;
};