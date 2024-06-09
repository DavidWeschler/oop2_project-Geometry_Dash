#pragma once

#include "Static.h"

class Spike : public Static
{
public:
	Spike(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
		: Static(world, texture, color, position) {};

	virtual void stam() {};

private:

};