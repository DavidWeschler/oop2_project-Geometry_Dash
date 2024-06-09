#pragma once

#include "Object.h"

class Static : public Object
{
public:
	//Static() {};
	Static(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
		: Object(world, texture, color, position) {};

	virtual ~Static() override;
	virtual void stam() = 0;
};