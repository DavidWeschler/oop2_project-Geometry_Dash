#pragma once

#include "Static.h"

class GroundJump : public Static
{
public:
	GroundJump(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
		: Static(world, texture, color, position) {};

};